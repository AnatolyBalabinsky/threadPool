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

#include "task/itask.h"
#include "reader/reader.h"

class ThreadPool {
public:

    ThreadPool( uint32_t& threadCount, std::string& dirPath );

    void addTask( Reader::FileData fileData );

    void stop();

    float getResult();


private:

    bool isReading = true;
    bool threadsCreated = false;
    float result = 0;

    uint32_t threadCount;
    std::string dirPath;
    std::mutex mtx;

    void processing();
    void reading();

    std::thread read;
    std::vector< std::thread > threads;

    std::queue< Reader::FileData > taskQueue;

};

#endif
