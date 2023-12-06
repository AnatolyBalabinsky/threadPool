#include <filesystem>
#include "threadPool/threadPool.h"

ThreadPool::ThreadPool( uint32_t& threadCount, std::string& dirPath ) : threadCount( threadCount ), dirPath( dirPath ) {

    read = std::thread( &ThreadPool::reading, this );

    threads.reserve( threadCount );

    for( uint32_t i = 0; i < threadCount; ++i ) {
        threads.emplace_back( std::thread( &ThreadPool::processing, this ) );
    }

    std::lock_guard< std::mutex > lock( mtx );
    threadsCreated = true;

}

void ThreadPool::addTask( Reader::FileData fileData ) {

    std::lock_guard< std::mutex > lock( mtx );
    taskQueue.push( fileData );

}

void ThreadPool::stop() {

    read.join();

    for( uint32_t i = 0; i < threadCount; ++i ) {
        threads[ i ].join();
    }

}

float ThreadPool::getResult() {
    return result;
}

void ThreadPool::processing() {
// {
// std::lock_guard< std::mutex > lock( mtx );
// std::cout << "start thread with id: " << std::this_thread::get_id() << std::endl;
// }
    TaskFactory factory;
    auto taskSum = factory.createTask( TaskFactory::TaskType::sum );
    auto taskMult = factory.createTask( TaskFactory::TaskType::mult );
    auto taskSumSqr = factory.createTask( TaskFactory::TaskType::sumSqr );

    while( true ) {
        if( threadsCreated ) {
            float currRes;

            Reader::FileData data;

            {
                std::lock_guard< std::mutex > lock( mtx );
                if( !taskQueue.empty() ) {

                    data = taskQueue.front();
                    taskQueue.pop();

                    // std::cout << "poped queue, size of queue: " << taskQueue.size() << std::endl;

                }
            }
            if( !data.fileData.empty() ) {

                if( data.operType == 1 ) {
                    currRes = taskSum->process( data.fileData );
                }
                if( data.operType == 2 ) {
                    currRes = taskMult->process( data.fileData );
                }
                if( data.operType == 3 ) {
                    currRes = taskSumSqr->process( data.fileData );
                }

                {
                    std::lock_guard< std::mutex > lock( mtx );
                    data.fileData.clear();
                    result += currRes;
                    // std::cout << "ThreadId = " << std::this_thread::get_id() << " Result = " << result << std::endl;
                }
            }


            {
                std::lock_guard< std::mutex > lock( mtx );
                currRes = 0;
            }

            {
                std::lock_guard< std::mutex > lock( mtx );
                if( taskQueue.empty() && isReading == false ) {
                    break;
                }
            }

        }
    }

    std::lock_guard< std::mutex > lock( mtx );
    // std::cout << "stop thread with id: " << std::this_thread::get_id() << std::endl;
}

void ThreadPool::reading() {

    {
        std::lock_guard< std::mutex > lock( mtx );
        // std::cout << "start thread reading" << std::endl;
    }

    std::filesystem::path directory( dirPath );

    if( !std::filesystem::exists( directory ) ) {

        throw std::runtime_error( "Директория не существует" );

    }

    std::filesystem::directory_iterator begin( directory );
    std::filesystem::directory_iterator end;

    for( ; begin != end; ++begin ) {

        {
            // std::lock_guard< std::mutex > lock( mtx );
            std::unique_lock< std::mutex > lock( mtx );
            if( begin->path().filename() == "out.dat" ) {
                continue;
            }

            Reader reader( begin->path() );
            taskQueue.push( reader.getFileData() );
            // std::cout << "added a file, size of queue: " << taskQueue.size() << std::endl;
            lock.unlock();
        }
        // std::this_thread::sleep_for( std::chrono::microseconds( 1 ) );
    }

    {
        std::lock_guard< std::mutex > lock( mtx );
        isReading = false;

        // std::cout << "stop thread reading" << std::endl;
    }

}
