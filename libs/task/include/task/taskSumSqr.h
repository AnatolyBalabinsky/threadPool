#ifndef TASKSUMSQR_H
#define TASKSUMSQR_H

#include <vector>

#include "itask.h"

class TaskSumSqr: public ITask {
public:

    void process() override;
    virtual ~TaskSumSqr() = default;

    // TaskSumSqr( const std::vector< float >& data );
    void setData( const std::vector< float >& data );
    float getResult() const;

private:
    std::vector< float > data;
    float result { };


};

#endif
