#include <filesystem>
#include "threadPool/threadPool.h"

ThreadPool::ThreadPool( uint32_t& threadCount ) : threadCount( threadCount ) {

    threads.reserve( threadCount );

    for( uint32_t i = 0; i < threadCount; ++i ) {
        threads.emplace_back( &ThreadPool::processing, this );
    }

}

void ThreadPool::addTask( std::unique_ptr< ITask > task ) {

    std::lock_guard< std::mutex > lock( mtx );
    taskQueue.push( std::move( task ) );

}

void ThreadPool::stopCreatingTask() {

    std::lock_guard< std::mutex > lock( mtx );
    this->isCreatingTask = false;

}

void ThreadPool::stop() {

    stopCreatingTask();

    for( uint32_t i = 0; i < threadCount; ++i ) {
        threads[ i ].join();
    }

}

bool ThreadPool::canStop() {

    if( !isCreatingTask ) {

        if( taskQueue.empty() ) {
            return true;
        }
    }

    return false;
}

void ThreadPool::processing() {

    while( true ) {

        std::unique_ptr< ITask > task;

        {
            std::lock_guard< std::mutex > lock( mtx );
            if( !taskQueue.empty() ) {

                task = std::move( taskQueue.front() );
                taskQueue.pop();

            }
        }

        if( task.get() != nullptr ) {
            task->process();
        }

        std::lock_guard< std::mutex > lock( mtx );

        if( canStop() ) {
            break;
        }

    }
}

