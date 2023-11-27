#ifndef TASKMULT_H
#define TASKMULT_H

#include "itask.h"

class TaskMult: public ITask {
public:

    float process( const std::vector< float >& data ) override;
    virtual ~TaskMult() = default;

};

#endif
