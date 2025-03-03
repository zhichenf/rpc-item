#ifndef RPC_SRC_INCLUDE_MPRPCAPPLICATION_H_
#define RPC_SRC_INCLUDE_MPRPCAPPLICATION_H_

#include "mprpc_configure.h"
#include "mprpc_channel.h"
#include "mprpc_controller.h"

//rpc应用类
class MprpcApplication {
public:
    static void Init(int argc, char**argv);
    static MprpcApplication& GetInstance();
    static MprpcConfigure& GetConfigure();
private:

    static MprpcConfigure config_;

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication(MprpcApplication&&) = delete;
};



#endif