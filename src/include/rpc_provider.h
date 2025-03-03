#ifndef RPC_SRC_INCLUDE_RPCPROVIDER_H_
#define RPC_SRC_INCLUDE_RPCPROVIDER_H_

#include <memory>
#include <unordered_map>

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <google/protobuf/service.h>

//rpc提供者类，会创建一个rpc服务器
class RpcProvider {
public:
    //使用抽象类，接受任意的service
    void NotifyService(std::shared_ptr<google::protobuf::Service> service);

    //启动rpc节点，开始提供rpc远程网络调用服务
    void Run();

private:
    muduo::net::EventLoop event_loop_;

    struct ServiceInfo {
        std::shared_ptr<google::protobuf::Service> service;     //保存服务对象
        std::unordered_map<std::string,const google::protobuf::MethodDescriptor*> method_map_;   //服务方法 
    };

    std::unordered_map<std::string, ServiceInfo> service_map_;

    //专门处理用户的连接创建
    void OnConnection(const muduo::net::TcpConnectionPtr& conn);

    //读写事件的回调函数
    void OnMessage(const muduo::net::TcpConnectionPtr& conn,    //连接
                    muduo::net::Buffer* buffer,                //缓冲区
                    muduo::Timestamp time);                     //时间信息

    //closure的回调操作绑定的方法，用于序列化rpc的响应和网络发送
    void SendRpcResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*); 
    
};

#endif