#ifndef THREADPOOLTASKSUM_H
#define THREADPOOLTASKSUM_H

#include "threadPoolTask/iThreadPoolTask.h"

class ThreadPoolTaskSum: public IThreadPoolTask {
public:

    void process() override;
    virtual ~ThreadPoolTaskSum() = default;

};

#endif
