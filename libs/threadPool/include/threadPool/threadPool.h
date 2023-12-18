#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <thread>
#include <mutex>
#include <vector>
#include <cstdint>
#include <queue>

#include "task/itask.h"

class ThreadPool {
public:

    ThreadPool( uint32_t& threadCount );

    void addTask( std::unique_ptr< ITask > task );

    void stop();

private:

    void processing();

    void stopCreatingTask();
    bool canStop();

    bool isCreatingTask  {
        true
    };

    uint32_t threadCount;
    std::mutex mtx;

    std::vector< std::thread > threads;
    std::queue< std::unique_ptr< ITask > > taskQueue;

};

#endif
