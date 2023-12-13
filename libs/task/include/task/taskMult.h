#ifndef TASKMULT_H
#define TASKMULT_H

#include <vector>

#include "task/taskCalculate.h"

class TaskMult: public TaskCalculate {
public:

    void process() override;
    virtual ~TaskMult() = default;

};

#endif
