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

    std::vector< std::string > setFilesPaths( const std::string& dirPath );

    float oneThread( const std::string& dirPath );
    float multipleThread( const std::string& dirPath );
    float pool( uint32_t threadCount, const std::string& dirPath );

};

#endif
