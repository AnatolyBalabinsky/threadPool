#ifndef TASKSUM_H
#define TASKSUM_H

#include <vector>

#include "task/taskCalculate.h"

class TaskSum: public TaskCalculate {
public:

    void process() override;
    virtual ~TaskSum() = default;

};

#endif
