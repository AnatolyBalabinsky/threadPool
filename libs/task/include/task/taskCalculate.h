#ifndef TASKCALCULATE_H
#define TASKCALCULATE_H

#include <vector>

#include "task/itask.h"

class TaskCalculate: public ITask {
public:

    virtual ~TaskCalculate() = default;

    virtual void setData( const std::vector< float >& data );
    virtual float getResult() const;

protected:

    std::vector< float > data;
    float result { };

};


#endif
