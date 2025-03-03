#include "mprpc_application.h"

#include <unistd.h>

#include <iostream>

MprpcConfigure MprpcApplication::config_;

void showArgsHelp() {
    std::cout << "format: command -i <configfile>" << std::endl;
}

void MprpcApplication::Init(int argc, char**argv) {
    if (argc < 2) {
        showArgsHelp();
        exit(EXIT_FAILURE); 
    }

    int c = 0;
    std::string config_file;
    while ((c = getopt(argc,argv,"i:")) != -1) {
        switch(c) {
            case 'i':
                config_file = optarg;
                break;
            case '?':
                showArgsHelp();
                exit(EXIT_FAILURE);
            case ':':
                showArgsHelp();
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    //开始加载配置文件 rpcserver_ip= rpcserver_port= zookeeper_ip= zookeeper_port=
    config_.LoadConfigureFile(config_file.c_str());

    std::cout << config_.Load("rpcserverip") << std::endl;
    std::cout << config_.Load("rpcserverport") << std::endl;
    std::cout << config_.Load("zookeeperip") << std::endl;
    std::cout << config_.Load("zookeeperport") << std::endl;
    std::cout << config_.Load("is null") << std::endl;

}

MprpcApplication& MprpcApplication::GetInstance() {
    static MprpcApplication app;
    return app;
}

MprpcConfigure& MprpcApplication::GetConfigure() {
    return config_;
}