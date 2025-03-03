#include <iostream>
#include <memory>

#include "public/user.pb.h"
#include "mprpc_application.h"
#include "rpc_provider.h"

//原来是一个本地服务，提供了两个进程内的本地方法

//业务代码，不是框架代码！！！！！！

//让本地服务继承protobuf生成的服务，重写protobuf给的login函数
class UserService : public fixbug::UserServiceRpc {
public:

    bool Login(std::string name, std::string pwd) {
        std::cout << "do login service" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "password: " << pwd << std::endl;
        return true;
    }

    bool Register(uint32_t id, std::string name, std::string pwd) {
        std::cout << "do login service" << std::endl;
        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "password: " << pwd << std::endl;
        return true;
    }

    //重写UserServiceRpc的Login方法,下面的方法由框架直接调用
    void Login(google::protobuf::RpcController* controller,
        const ::fixbug::LoginRequest* request,
        ::fixbug::LoginResponse* response,
        ::google::protobuf::Closure* done) {
        
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool login_res = Login(name,pwd);       //本地业务
        
        //把响应交给框架去返回
        fixbug::ResultCode* code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response->set_success(login_res);
        
        //执行回调操作
        done->Run();
    }

    void Register(google::protobuf::RpcController* controller,
        const ::fixbug::RegisterRequest* request,
        ::fixbug::RegisterResponse* response,
        ::google::protobuf::Closure* done) {

        uint32_t id = request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool register_res = Register(id,name,pwd);
        fixbug::ResultCode* code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response->set_success(register_res);

        done->Run();
        
    }
};

int main(int argc, char** argv) {       //使用框架的案例 
    //调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    RpcProvider provider;       //生成一个服务提供者

    //服务器初始化有这里提供哪些服务
    provider.NotifyService(std::make_shared<UserService>());

    //提供者运行服务，打开rpc服务器
    provider.Run();

    return 0;
}

