#include "mprpc_configure.h"

#include <iostream>
#include <string>
#include <cstring>

#include "file_guard.h"

//解析加载配置文件
void MprpcConfigure::LoadConfigureFile(const char* config_file) {
    FileGuard file(config_file, "r");
    while(!feof(file.GetFile())) {
        char buf[512] = {0};
        fgets(buf, 512, file.GetFile());
        int index = 0;
        //去掉所有的的空格和换行符
        for (int i = 0; i < strlen(buf); ++i) {
            if (buf[i] != ' ' && buf[i] != '\n') {
                buf[index++] = buf[i];
            }
        }
        buf[index] = '\0';
        if (0 == index) {
            continue;
        }
        std::string str(buf);
        str.substr(index);
        if (str[0] == '#') {    //忽略注释
            continue;
        }
        index = str.find("=");
        std::string key = str.substr(0,index);
        std::string value = str.substr(index+1);
        conf_map_[key] = value;
    }
}   

//查询配置信息
std::string MprpcConfigure::Load(const std::string& key) {
    if (conf_map_.find(key) == conf_map_.end()) {
        return "null";
    }
    return conf_map_[key];
}