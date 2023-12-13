#include <filesystem>
#include <numeric>

#include "fileCalculator/fileCalculator.h"
#include "writer/writer.h"
#include "task/taskfactory.h"
#include "threadPool/threadPool.h"

std::vector< std::string > FileCalculator::setFilesPaths(const std::string &dirPath ) {

    std::vector< std::string > filesPaths;
    std::filesystem::path directory( dirPath );

    if( !std::filesystem::exists( directory ) ) {
        throw std::runtime_error( "Директория не существует" );
    }

    std::filesystem::directory_iterator begin( directory );
    std::filesystem::directory_iterator end;

    for( ; begin != end; ++begin ) {

        if( begin->path().filename() == "out.dat" ) {
            continue;
        }

        filesPaths.push_back( begin->path() );

    }
    return filesPaths;
}

float FileCalculator::oneThread(const std::string &dirPath ) {

    std::vector< std::string > filesPaths = setFilesPaths( dirPath );

    std::vector< float > filesResults( filesPaths.size() );

    for( uint32_t i = 0; i != filesPaths.size(); i++ ) {

        auto task = TaskFactory::create( TaskFactory::TaskType::readCalc );
        auto taskReadCalc = dynamic_cast< TaskReadCalc* >( task.get() );
        taskReadCalc->setFilePath( filesPaths[ i ] );
        taskReadCalc->setResult( &filesResults[ i ] );
        task->process();

    }

    float result = std::accumulate( filesResults.begin(), filesResults.end(), 0.0f );

    Writer writer( "myOut.dat" );
    writer.write( result );

    return result;
}

float FileCalculator::multipleThread(const std::string &dirPath ) {

    std::vector< std::string > filesPaths = setFilesPaths( dirPath );

    std::vector< float > filesResults( filesPaths.size() );
    std::vector< std::thread > threads;

    for( uint32_t i = 0; i != filesPaths.size(); i++ ) {

        auto task = TaskFactory::create( TaskFactory::TaskType::readCalc );
        auto taskReadCalc = dynamic_cast< TaskReadCalc* >( task.get() );
        taskReadCalc->setFilePath( filesPaths[ i ] );
        taskReadCalc->setResult( &filesResults[ i ] );

        threads.push_back( std::thread( &TaskReadCalc::process, *taskReadCalc  )  );

    }

    for( uint32_t i = 0; i < threads.size(); ++i ) {
        threads[ i ].join();
    }

    float result = std::accumulate( filesResults.begin(), filesResults.end(), 0.0f );

    Writer writer( "myOut.dat" );
    writer.write( result );

    return result;
}

float FileCalculator::pool(uint32_t threadCount, const std::string &dirPath ) {

    std::vector< std::string > filesPaths = setFilesPaths( dirPath );
    std::vector< float > filesResults( filesPaths.size() );

    TaskFactory::TaskType type = TaskFactory::TaskType::readCalc;

    ThreadPool pool( threadCount );

    for( uint32_t i = 0; i != filesPaths.size(); i++ ) {

        auto task = TaskFactory::create( type );
        auto taskReadCalc = dynamic_cast< TaskReadCalc* >( task.get() );

        taskReadCalc->setFilePath( filesPaths[ i ] );
        taskReadCalc->setResult( &filesResults[ i ] );

        auto taskU = std::make_unique< TaskReadCalc >( ( *taskReadCalc ) );

        pool.addTask( std::move( taskU ) );

    }

    pool.stop();

    float result = std::accumulate( filesResults.begin(), filesResults.end(), 0.0f );

    Writer writer( "myOut.dat" );
    writer.write( result );

    return result;

}


