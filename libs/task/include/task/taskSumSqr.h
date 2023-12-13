#ifndef TASKSUMSQR_H
#define TASKSUMSQR_H

#include <vector>

#include "task/taskCalculate.h"

class TaskSumSqr: public TaskCalculate {
public:

    void process() override;
    virtual ~TaskSumSqr() = default;

};

#endif
