#include "file_guard.h"

FileGuard::FileGuard(const char* file_name,const char* way) {
    file = fopen(file_name, way);
    if (nullptr == file) {
        std::cout << file_name << "is not exist" << std::endl;
        exit(EXIT_FAILURE);
    }
}

FileGuard::~FileGuard() {
    fclose(file);
}

FILE* FileGuard::GetFile() {
    return file;
}