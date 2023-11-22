#ifndef TASKSUMSQR_H
#define TASKSUMSQR_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "itask.h"

class TaskSumSqr: public ITask {
public:

    float process( const std::vector< float >& data ) override;
    virtual ~TaskSumSqr() = default;

};

#endif
