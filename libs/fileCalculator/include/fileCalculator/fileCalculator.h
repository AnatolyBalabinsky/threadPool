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

private:
    void reading( std::string dirPath );
    void processing( float& result, std::thread& read );
    std::mutex mtx;
    std::vector< Reader::FileData > fd;
};

#endif
