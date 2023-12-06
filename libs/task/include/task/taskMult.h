#ifndef TASKMULT_H
#define TASKMULT_H

#include <vector>

#include "itask.h"

class TaskMult: public ITask {
public:

    void process() override;

    virtual ~TaskMult() = default;

    // TaskMult( const std::vector< float >& data );

    void setData( const std::vector< float >& data );
    float getResult() const;

private:
    std::vector< float > data;
    float result { };

};

#endif
