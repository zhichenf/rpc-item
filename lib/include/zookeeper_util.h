#ifndef RPC_SRC_INCLUDE_ZOOKEEPERUTIL_H_
#define RPC_SRC_INCLUDE_ZOOKEEPERUTIL_H_

#include <semaphore.h>

#include <string>

#include <zookeeper/zookeeper.h>

class ZkClient {
public:
    ZkClient();
    ~ZkClient();

    //启动连接zkServer
    void Start();

    //创建znode节点
    void Create(const char* path, const char* data, int datalen, int state = 0);
    
    //根据指定路径获得对应节点的值
    std::string GetData(const char* path);
private:

    //客户端句柄
    zhandle_t* zhandle_;
};

#endif