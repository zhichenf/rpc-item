#include "mprpc_channel.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <string>

#include "rpcheader.pb.h"
#include "mprpc_application.h"
#include "mprpc_controller.h"
#include "zookeeper_util.h"

class FdGuard {
public:
    FdGuard(int fd) : fd_(fd) {}
    ~FdGuard() {close(fd_);}
    int GetFd() {return fd_;}
private:
    int fd_;
};

void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
    google::protobuf::RpcController* controller, const google::protobuf::Message* request,
    google::protobuf::Message* response, google::protobuf::Closure* done) {
    
    const google::protobuf::ServiceDescriptor* sd = method->service();
    std::string service_name = sd->name();
    std::string method_name = method->name();

    //获取参数的序列化字符串长度
    uint32_t args_size = 0;
    std::string args_str;
    if (request->SerializeToString(&args_str)) {
        args_size = args_str.size();
        std::cout << "size: " << args_size << " args_Str: " << args_str << std::endl;
    } else {
        controller->SetFailed("serialize request error!!!");
        return;
    }

    //定义rpc请求header
    mprpc::RpcHeader rpc_header;
    
    rpc_header.set_service_name(service_name);
    rpc_header.set_method_name(method_name);
    rpc_header.set_args_size(args_size);

    uint32_t header_size = 0;
    std::string rpc_header_str;
    if (rpc_header.SerializeToString(&rpc_header_str)) {
        header_size = rpc_header_str.size();
    } else {
        controller->SetFailed("serialize request error!!!");
        return;
    }

    //  组织rpc请求字符串
    std::string send_rpc_str;
    send_rpc_str.insert(0,std::string(reinterpret_cast<char*>(&header_size),4));
    send_rpc_str += rpc_header_str;
    send_rpc_str += args_str;
    
    //打印调式信息
    std::cout << "====================================" << std::endl;
    std::cout << "header_size: " << header_size << std::endl;
    std::cout << "rpc_header_Str: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "====================================" << std::endl;

    //网络发送
    FdGuard clientfd(socket(AF_INET,SOCK_STREAM, 0));
    if (-1 == clientfd.GetFd()) {
        char buf[512] = {0};
        sprintf(buf,"errno: %d", errno);
        controller->SetFailed(buf);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;

    // std::string ip = MprpcApplication::GetInstance().GetConfigure().Load("rpcserverip");
    // uint16_t port = atoi(MprpcApplication::GetInstance().GetConfigure().Load("rpcserverport").c_str());

    //使用zookeeper找到发布服务的服务器
    ZkClient zk_client;
    zk_client.Start();

    std::string method_path = "/" + service_name + "/" + method_name;
    std::string host_data = zk_client.GetData(method_path.c_str());
    int idx = host_data.find(":");
    if (idx == -1) {
        controller->SetFailed(method_path + "address is invalid!");
        return;
    }

    std::string ip = host_data.substr(0,idx);
    uint16_t port = atoi(host_data.substr(idx+1).c_str());

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if (-1 == connect(clientfd.GetFd(), reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr))) {
        controller->SetFailed("connect error!");
        exit(EXIT_FAILURE);
    }
    
    //发送rpc请求
    if (-1 == send(clientfd.GetFd(),send_rpc_str.c_str(), send_rpc_str.size(), 0)) {
        controller->SetFailed("connect error!");
        char buf[512];
        sprintf(buf,"connect error! errno: %d",errno);
        controller->SetFailed(buf);
        return;
    }

    //接受rpc请求的响应
    char recv_buf[1024] = {0};
    int recv_size = 0;
    if ( -1 == (recv_size = recv(clientfd.GetFd(), recv_buf,sizeof(recv_buf),0))) {
        controller->SetFailed("recive error!");
        return;
    }

    if (!response->ParseFromArray(recv_buf, recv_size)) {
        controller->SetFailed("parse error!");
        return;
    }

} 