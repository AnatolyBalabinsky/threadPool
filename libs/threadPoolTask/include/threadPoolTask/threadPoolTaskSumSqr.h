#ifndef THREADPOOLTASKSUMSQR_H
#define THREADPOOLTASKSUMSQR_H

#include "threadPoolTask/iThreadPoolTask.h"

class ThreadPoolTaskSumSqr: public IThreadPoolTask {
public:

    void process() override;
    virtual ~ThreadPoolTaskSumSqr() = default;

};

#endif
