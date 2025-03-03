#include "rpc_provider.h"

#include <functional>

#include <google/protobuf/descriptor.h>

#include "mprpc_application.h"
#include "rpcheader.pb.h"


//使用抽象类，接受任意的service，框架对外提供的接口，告知框架要使用的服务类型
void RpcProvider::NotifyService(std::shared_ptr<google::protobuf::Service> service) {
    //服务信息， 包括服务对象和服务的方法表
    ServiceInfo service_info;

    //获取服务描述
    const google::protobuf::ServiceDescriptor* service_desc = service->GetDescriptor();
    std::string service_name = service_desc->name();        //获取服务名
    int method_cnt = service_desc->method_count();      //获取服务的方法个数

    //完善服务信息
    for (int i = 0; i < method_cnt; ++i) {
        //通过服务描述获取方法描述
        const google::protobuf::MethodDescriptor* method_desc = service_desc->method(i);
        std::string method_name = method_desc->name();
        service_info.method_map_.insert({method_name, method_desc});
    }
    service_info.service = service;

    //往服务列表添加服务
    service_map_.insert({service_name,service_info});
}

//启动rpc节点，开始提供rpc远程网络调用服务
void RpcProvider::Run() {
    std::string ip = MprpcApplication::GetInstance().GetConfigure().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfigure().Load("rpcserverport").c_str());
    muduo::net::InetAddress address(ip,port);

    //创建tcp_server对象
    muduo::net::TcpServer tcp_server(&event_loop_,address,"RpcProvider");

    using namespace std::placeholders;
    //设置新连接创建和断开的回调函数
    tcp_server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, _1));

    //设置用户读写事件的回调函数
    tcp_server.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, _1, _2, _3));
    
    //设置线程数量，1个IO线程，3个work线程

    tcp_server.setThreadNum(4);
    tcp_server.start();
    event_loop_.loop();
}

 //专门处理用户的连接创建
void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr& conn) {
    if(!conn->connected()) {
        conn->shutdown();
    }
}

/*
    框架内部，RpcProvider 和 RpcConsumer要协商好通信之间的protobuf的数据类型
*/
 //读写事件的回调函数，收到rpc任务请求后要做的事情
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr& conn,    //连接
                 muduo::net::Buffer* buffer,                //缓冲区
                 muduo::Timestamp time) {      //时间信息
    std::string recv_buf = buffer->retrieveAllAsString();
    //tcp通信的粘包问题，头部标记长度
    uint32_t header_size = 0;
    recv_buf.copy((char*)&header_size, 4, 0);
    
    //根据header_size读取数据头的原始字符流
    std::string rpc_header_str = recv_buf.substr(4,header_size);
    mprpc::RpcHeader rpc_header;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    if (rpc_header.ParseFromString(rpc_header_str)) {
        //数据头序列化成功
        service_name = rpc_header.service_name();
        method_name = rpc_header.method_name();
        args_size = rpc_header.args_size();
    } else {
        //数据头序列化失败
        std::cout << "rpc_header_str: " << rpc_header_str << " parse error!" << std::endl;
        return;
    }

    std::string args_str = recv_buf.substr(4+header_size, args_size);

    //打印调式信息
    std::cout << "====================================" << std::endl;
    std::cout << "header_size: " << header_size << std::endl;
    std::cout << "rpc_header_Str: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "====================================" << std::endl;

    //找到服务名对应的服务
    auto it = service_map_.find(service_name);
    if (it == service_map_.end()) {
        std::cout << service_name << " no service" << std::endl;
        return;
    }

    //找到该服务中方法名对应的方法 it->second是ServiceInfo结构体
    auto mit = it->second.method_map_.find(method_name);
    if (mit == it->second.method_map_.end()) {
        std::cout << method_name << " no method" << std::endl;
        return; 
    }

    //获取服务对象
    std::shared_ptr<google::protobuf::Service>service = it->second.service;
    //获取方法的描述
    const google::protobuf::MethodDescriptor* method = mit->second;

    //生成rpc方法调用的请求request和响应response参数
    google::protobuf::Message* request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(args_str)) {
        std::cout << "request parse error, content: " << args_str << std::endl;
        return;
    }

    //生成response对象用于回复
    google::protobuf::Message* response = service->GetResponsePrototype(method).New();

    //给下面的method方法的调用绑定一个closure的回调函数，任务处理完成后执行回调函数
    google::protobuf::Closure* done = 
        google::protobuf::NewCallback<RpcProvider, const muduo::net::TcpConnectionPtr&, google::protobuf::Message*>(this, &RpcProvider::SendRpcResponse, conn, response);

    //在框架上根据远端rpc请求，调用当前rpc节点上调用的方法。
    service->CallMethod(method, nullptr,request, response, done);
}            

//closure的回调操作绑定的方法，用于序列化rpc的响应和网络发送
void RpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* response) {
    std::string response_str;
    if (response->SerializeToString(&response_str)) {
        //序列化成功后，通过网络把rpc方法执行的结果发送回rpc的调用方
        conn->send(response_str);
        conn->shutdown();           //http的短链接服务
    } else {
        std::cout << "serialize response_str error " << std::endl;
        conn->shutdown();
    }
}   