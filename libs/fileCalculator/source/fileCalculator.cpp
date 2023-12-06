#include <filesystem>

#include "fileCalculator/fileCalculator.h"
#include "writer/writer.h"
#include "task/taskMult.h"
#include "task/taskSum.h"
#include "task/taskSumSqr.h"
#include "threadPool/threadPool.h"

float FileCalculator::oneThread( std::string dirPath ) {

    std::filesystem::path directory( dirPath );

    if( !std::filesystem::exists( directory ) ) {
        throw std::runtime_error( "Директория не существует" );
    }

    std::filesystem::directory_iterator begin( directory );
    std::filesystem::directory_iterator end;

    float result = 0;

    for( ; begin != end; ++begin ) {

        if( begin->path().filename() == "out.dat" ) {
            continue;
        }

        Reader reader( begin->path() );
        Reader::FileData fd = reader.getFileData();

// TaskFactory factory;
// TaskFactory::TaskType type;
// if( fd.operType == 1 ) {
// type = TaskFactory::TaskType::sum;
// }
// if( fd.operType == 2 ) {
// type = TaskFactory::TaskType::mult;
// }
// if( fd.operType == 3 ) {
// type = TaskFactory::TaskType::sumSqr;
// }

        auto task = TaskFactory::createTask( static_cast< TaskFactory::TaskType >( fd.operType ) );
        auto currRes = task->process( fd.fileData );
        result += currRes;

    }

    Writer writer( "myOut.dat" );
    writer.write( result );

    return result;
}

void FileCalculator::processing( float& result, std::thread& read ) {

    TaskFactory factory;
    auto taskSum = factory.createTask( TaskFactory::TaskType::sum );
    auto taskMult = factory.createTask( TaskFactory::TaskType::mult );
    auto taskSumSqr = factory.createTask( TaskFactory::TaskType::sumSqr );

    float currRes = 0;

    while( read.joinable() ) {
        while( !fd.empty() ) {

            {
                std::lock_guard< std::mutex > lock( mtx );// блокируем доступ к данным
                auto currentElement = fd.begin();

                if( currentElement->operType == 1 ) {
                    currRes = taskSum->process( currentElement->fileData );
                }
                if( currentElement->operType == 2 ) {
                    currRes = taskMult->process( currentElement->fileData );
                }
                if( currentElement->operType == 3 ) {
                    currRes = taskSumSqr->process( currentElement->fileData );
                }


                fd.erase( currentElement );
                result += currRes;
            }
        }
    }
}

void FileCalculator::reading( std::string dirPath ) {

    std::filesystem::path directory( dirPath );

    if( !std::filesystem::exists( directory ) ) {

        throw std::runtime_error( "Директория не существует" );

    }

    std::filesystem::directory_iterator begin( directory );
    std::filesystem::directory_iterator end;

    for( ; begin != end; ++begin ) {

        std::lock_guard< std::mutex > lock( mtx );
        if( begin->path().filename() == "out.dat" ) {
            continue;
        }

        Reader reader( begin->path() );
        fd.push_back( reader.getFileData() );

    }
}

float FileCalculator::multipleThread( std::string dirPath ) {


    float result = 0;

    std::thread read( &FileCalculator::reading, this, dirPath );
    std::thread proc( &FileCalculator::processing, this,  std::ref( result ), std::ref( read ) );

    read.join();
    proc.join();

    return result;
}

float FileCalculator::pool( uint32_t threadCount, std::string dirPath ) {

    ThreadPool pool( threadCount, dirPath );
    pool.stop();

    return pool.getResult();

}


