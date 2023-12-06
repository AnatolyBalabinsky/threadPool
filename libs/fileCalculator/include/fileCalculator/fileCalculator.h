#ifndef FILECALCULATOR_H
#define FILECALCULATOR_H

#include <string>
#include <thread>
#include <mutex>
#include <vector>

#include "reader/reader.h"

class FileCalculator {
public:

    FileCalculator() = default;

    float oneThread( std::string dirPath );
    float multipleThread( std::string dirPath );
    float pool( uint32_t threadCount, std::string dirPath );

private:

    float getFileResult( std::string filePath );
    void getFileResultWhrap( std::string filePath, float& result );

    std::vector< std::string > getFilesPaths( std::string dirPath );

    void reading( std::string dirPath );
    void processing( float& result, std::thread& read );

    std::mutex mtx;
    std::vector< Reader::FileData > fd;

};

#endif
