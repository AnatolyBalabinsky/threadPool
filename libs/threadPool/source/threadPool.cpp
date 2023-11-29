#include "threadPool/threadPool.h"

ThreadPool::ThreadPool( uint32_t threadCount ) : threadCount( threadCount ) {

    threads.reserve( threadCount );

    for( uint32_t i = 0; i < threadCount; ++i ) {
        threads.emplace_back( &ThreadPool::processing, this );
    }
}

void ThreadPool::addTask( ITask* task ) {
    taskQueue.push( task );
}

void ThreadPool::start() {

    for( uint32_t i = 0; i < threadCount; ++i ) {
        threads[ i ].join();
    }

}

void ThreadPool::processing() {

    TaskFactory factory;

    while( !taskQueue.empty() ) {


        taskQueue.front();
        taskQueue.pop();



    }
}
