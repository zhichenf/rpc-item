#include "logger.h"

#include <time.h>

#include <iostream>

#include "file_guard.h"

void Logger::SetLogLevel(LogLevel log_level) {
    log_level_ = log_level;
}

void Logger::Log(std::string msg) {
    lock_queue_.Push(msg);
}

Logger::Logger() {
    //启动专门的写日志线程
    std::thread write_log_task([&]() {
        for(;;) {
            time_t now = time(nullptr);
            tm* now_tm = localtime(&now);

            char file_name[128] = {0};
            sprintf(file_name, "%d-%d-%d-lob.txt", now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday);
            FileGuard file_guard(file_name,"a+");
            if (nullptr == file_guard.GetFile()) {
                std::cout << "logger file " << file_name <<" open error!" << std::endl;
                exit(EXIT_FAILURE);
            }

            std::string msg = lock_queue_.Pop();

            char time_buf[512];
            sprintf(time_buf, "%d:%d:%d::", now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec);
            msg.insert(0,time_buf);  
            msg.append("\n");
            fputs(msg.c_str(),file_guard.GetFile());
        }
    });
    write_log_task.detach();
}

Logger& Logger::GetInstance() {
    static Logger logger;
    return logger;
}