#include <filesystem>
#include <numeric>

#include "fileCalculator/fileCalculator.h"
#include "writer/writer.h"
#include "task/taskMult.h"
#include "task/taskSum.h"
#include "task/taskSumSqr.h"
#include "threadPool/threadPool.h"

std::vector< std::string > FileCalculator::getFilesPaths( std::string dirPath ) {

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

float FileCalculator::getFileResult( std::string filePath ) {

    Reader reader( filePath );
    Reader::FileData fd = reader.getFileData();

    auto task = TaskFactory::createTask( static_cast< TaskFactory::TaskType >( fd.operType ) );
    return task->process( fd.fileData );

}

void FileCalculator::getFileResultWhrap( std::string filePath, float& result ) {
    result = getFileResult( filePath );
}


float FileCalculator::oneThread( std::string dirPath ) {

    std::vector< std::string > filesPaths = getFilesPaths( dirPath );

    std::vector< float > filesResults( filesPaths.size() );

    for( uint32_t i = 0; i != filesPaths.size(); i++ ) {

        getFileResultWhrap( filesPaths[ i ], filesResults[ i ] );

    }

    float result = std::accumulate( filesResults.begin(), filesResults.end(), 0.0f );

    Writer writer( "myOut.dat" );
    writer.write( result );

    return result;
}

float FileCalculator::multipleThread( std::string dirPath ) {

    std::vector< std::string > filesPaths = getFilesPaths( dirPath );

    std::vector< float > filesResults( filesPaths.size() );
    std::vector< std::thread > threads;

    for( uint32_t i = 0; i != filesPaths.size(); i++ ) {

        threads.push_back( std::thread( &FileCalculator::getFileResultWhrap, this, filesPaths[ i ], std::ref( filesResults[ i ] ) ) );

    }

    for( uint32_t i = 0; i < threads.size(); ++i ) {
        threads[ i ].join();
    }

    float result = std::accumulate( filesResults.begin(), filesResults.end(), 0.0f );

    Writer writer( "myOut.dat" );
    writer.write( result );

    return result;
}

float FileCalculator::pool( uint32_t threadCount, std::string dirPath ) {

    ThreadPool pool( threadCount, dirPath );
    pool.stop();

    return pool.getResult();

}


