#ifndef RPC_SRC_INCLUDE_MPRPCCONFIGURE_H_
#define RPC_SRC_INCLUDE_MPRPCCONFIGURE_H_

#include <unordered_map>
#include <string>

//管理配置文件类
class MprpcConfigure {
public:
    //解析加载配置文件
    void LoadConfigureFile(const char* config_file);
    //查询配置信息
    std::string Load(const std::string& key);

private:
    std::unordered_map<std::string,std::string> conf_map_;
};

#endif