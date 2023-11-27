#ifndef TASKSUM_H
#define TASKSUM_H

#include "itask.h"

class TaskSum: public ITask {
public:

    float process( const std::vector< float >& data ) override;
    virtual ~TaskSum() = default;

};

#endif
