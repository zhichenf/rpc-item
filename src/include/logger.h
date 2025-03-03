#ifndef RPC_SRC_INCLUDE_LOGGER_H_
#define RPC_SRC_INCLUDE_LOGGER_H_

#include "lock_queue.h"


enum LogLevel{
    INFO,   //普通信息
    ERROR   //错误信息
};

//mprpc框架提供的日志系统
class Logger {
public:
    //设置日志级别
    void SetLogLevel(LogLevel log_level);
    
    //写日志
    void Log(std::string msg);

    static Logger& GetInstance();

private:
    LogLevel log_level_;
    LockQueue<std::string> lock_queue_;     //日志缓冲队列

    Logger();
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;
};

#define LOG_INFO(logmsgformat, ...) \
    do {        \
        Logger& logger = Logger::GetInstance(); \
        logger.SetLogLevel(INFO); \
        char c[1024] = {0}; \
        snprintf(c,1024,logmsgformat, ##__VA_ARGS__); \
        logger.Log(c); \
    } while(0);

#define LOG_ERR(logmsgformat, ...) \
do {        \
    Logger& logger = Logger::GetInstance(); \
    logger.SetLogLevel(ERROR); \
    char c[1024] = {0}; \
    snprintf(c,1024,logmsgformat, ##__VA_ARGS__); \
    logger.Log(c); \
} while(0);

#endif