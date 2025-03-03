#ifndef RPC_SRC_INCLUDE_FILEGUARD_H_
#define RPC_SRC_INCLUDE_FILEGUARD_H_

#include <stdio.h>

#include <iostream>

class FileGuard {
    public:
        FileGuard(const char* file_name,const char* way);
    
        ~FileGuard();
    
        FILE* GetFile();

        FileGuard(const FileGuard&) = delete;
        FileGuard& operator=(const FileGuard&) = delete;
    private:
        FILE* file;
    };

#endif