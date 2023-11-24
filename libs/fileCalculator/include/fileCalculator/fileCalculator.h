#ifndef FILECALCULATOR_H
#define FILECALCULATOR_H

#include <string>
#include <iostream>
#include <cstdint>
#include <filesystem>
#include "writer/writer.h"
#include "task/taskMult.h"
#include "task/taskSum.h"
#include "task/taskSumSqr.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include "reader/reader.h"

class FileCalculator {
public:

    FileCalculator() = default;

    float oneThread( std::string dirPath );
    float multipleThread( std::string dirPath );

private:

};

#endif
