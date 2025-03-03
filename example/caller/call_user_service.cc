#include <iostream>
#include <memory>

#include "mprpc_application.h"
#include "mprpc_channel.h"
#include "public/user.pb.h"


//业务代码，调用rpc服务

int main(int argc, char** argv) {
    //整个程序启动以后，想使用mprpc框架享受rpc服务调用，一定需要先调用框架的初始函数
    MprpcApplication::Init(argc, argv);

    //演示调用远程发布的rpc方法Login
    std::shared_ptr<MprpcChannel> mprpc_channel = std::make_shared<MprpcChannel>();
    fixbug::UserServiceRpc_Stub stub(mprpc_channel.get());

    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123");
    fixbug::LoginResponse response;
    
    stub.Login(nullptr,&request,&response,nullptr);

    //调用结束后，读取响应的结果
    if (0 == response.result().errcode()) {
        std::cout << "login success" << std::endl;
        std::cout << "rpc login response: " << response.success() << std::endl;
    } else {
        std::cout << "login failed" << std::endl;
    }

    fixbug::RegisterRequest register_request;
    register_request.set_id(1000);
    register_request.set_name("wangwu");
    register_request.set_pwd("123456");
    fixbug::RegisterResponse register_response;
    stub.Register(nullptr, &register_request, &register_response, nullptr);
}