#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <string>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <vector>
#include <cstdint>
#include <queue>
#include <atomic>
#include <future>
#include <unordered_set>
#include <task/itask.h>

class ThreadPool {
public:

    ThreadPool( uint32_t threadCount );

    void addTask( ITask* task );

    void start();


private:

    void processing();

    uint32_t threadCount;
    std::vector< std::thread > threads;

    std::queue< ITask* > taskQueue;

    bool stopped = false;
    std::mutex mtx;
    std::condition_variable cv;

};

#endif
