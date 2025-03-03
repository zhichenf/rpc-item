#include <iostream>
#include <memory>
#include <vector>

#include "public/friend.pb.h"
#include "mprpc_application.h"
#include "rpc_provider.h"
#include "logger.h"

//原来是一个本地服务，提供了两个进程内的本地方法

//业务代码，不是框架代码！！！！！！

//让本地服务继承protobuf生成的服务，重写protobuf给的login函数
class FriendService : public fixbug::FriendServiceRpc {
public:

    std::vector<std::string> GetFriendsList(uint32_t id) {
        std::cout << "do GetFriendsList service" << std::endl;
        std::cout << "id: " << id << std::endl;
        return {"zhang san", "li si", "wang wu"};
    }


    //重写UserServiceRpc的Login方法,下面的方法由框架直接调用
    void GetFriendsList(google::protobuf::RpcController* controller,
        const ::fixbug::GetFriendsListRequest* request,
        ::fixbug::GetFriendsListResponse* response,
        ::google::protobuf::Closure* done) {
        
        uint32_t id = request->id();

        std::vector<std::string> res = GetFriendsList(id);       //本地业务
        
        //把响应交给框架去返回
        fixbug::ResultCode* code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        for (int i = 0; i < res.size(); ++i) {
            std::string* p = response->add_friends();
            *p = res[i];
        }
        
        //执行回调操作
        done->Run();
    }
};

int main(int argc, char** argv) {       //使用框架的案例 
    LOG_INFO("first log message");
    LOG_ERR("%s:%s:%d",__FILE__, __FUNCTION__, __LINE__);
   
    //调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    RpcProvider provider;       //生成一个服务提供者

    //服务器初始化有这里提供哪些服务
    provider.NotifyService(std::make_shared<FriendService>());

    //提供者运行服务，打开rpc服务器
    provider.Run();


    return 0;
}