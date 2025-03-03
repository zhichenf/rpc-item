#ifndef RPC_SRC_INCLUDE_MPRPCCHANNEL_H_
#define RPC_SRC_INCLUDE_MPRPCCHANNEL_H_

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

class MprpcChannel : public google::protobuf::RpcChannel {

    //重写CallMethod方法，进行数据序列化和网络发送
    void CallMethod(const google::protobuf::MethodDescriptor* method,
        google::protobuf::RpcController* controller, const google::protobuf::Message* request,
        google::protobuf::Message* response, google::protobuf::Closure* done);
};

#endif