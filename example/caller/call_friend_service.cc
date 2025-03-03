#include <iostream>
#include <memory>

#include "mprpc_application.h"

#include "public/friend.pb.h"


//业务代码，调用rpc服务

int main(int argc, char** argv) {
    //整个程序启动以后，想使用mprpc框架享受rpc服务调用，一定需要先调用框架的初始函数
    MprpcApplication::Init(argc, argv);

    //演示调用远程发布的rpc方法Login
    std::shared_ptr<MprpcChannel> mprpc_channel = std::make_shared<MprpcChannel>();
    fixbug::FriendServiceRpc_Stub stub(mprpc_channel.get());

    fixbug::GetFriendsListRequest request;
    request.set_id(23);

    fixbug::GetFriendsListResponse response;
    MprpcController controller;
    stub.GetFriendsList(&controller,&request,&response,nullptr);

    if (!controller.Failed()) {
        //调用结束后，读取响应的结果
        if (0 == response.result().errcode()) {
            int friend_size = response.friends_size();
            for (int i = 0; i < friend_size; ++i) {
                std::cout << response.friends(i) << std::endl;
            }
        } else {    
            std::cout << "login failed" << std::endl;
        }
    } else {
        std::cout << controller.ErrorText() << std::endl;
    }

    
}