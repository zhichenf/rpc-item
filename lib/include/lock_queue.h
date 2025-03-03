#ifndef RPC_SRC_INCLUDE_LOCKQUEUE_H_
#define RPC_SRC_INCLUDE_LOCKQUEUE_H_

#include <mutex>
#include <queue>
#include <thread>
#include <condition_variable>

template<typename T>
class LockQueue {
public:
    void Push(const T& data) {
        std::unique_lock<std::mutex> ul(mutex_);
        que_.push(data);
        cond_var_.notify_one();
    }

    T Pop() {
        std::unique_lock<std::mutex> ul(mutex_);
        while( que_.empty()) {
            cond_var_.wait(ul);
        }

        T data = que_.front();
        que_.pop();
        return data;
    }

private:
    std::queue<T> que_;
    std::mutex mutex_;
    std::condition_variable cond_var_;
};

#endif