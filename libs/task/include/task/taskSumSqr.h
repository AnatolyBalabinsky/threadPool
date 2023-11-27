#ifndef TASKSUMSQR_H
#define TASKSUMSQR_H

#include "itask.h"

class TaskSumSqr: public ITask {
public:

    float process( const std::vector< float >& data ) override;
    virtual ~TaskSumSqr() = default;

};

#endif
