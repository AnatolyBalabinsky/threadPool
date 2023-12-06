#ifndef TASKSUM_H
#define TASKSUM_H

#include <vector>

#include "itask.h"

class TaskSum: public ITask {
public:

    void process() override;
    float getResult() const;

    virtual ~TaskSum() = default;

    // TaskSum( const std::vector< float >& data );

    void setData( const std::vector< float >& data );


private:
    std::vector< float > data;
    float result { };
};

#endif
