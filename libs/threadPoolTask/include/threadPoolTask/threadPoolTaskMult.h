#ifndef THREADPOOLTASKMULT_H
#define THREADPOOLTASKMULT_H

#include "threadPoolTask/iThreadPoolTask.h"

class ThreadPoolTaskMult: public IThreadPoolTask {
public:

    void process() override;

    void setFileData( const std::vector< float > data );
    float getResult();

    virtual ~ThreadPoolTaskMult() = default;

private:
    float result;
    std::vector< float > fileData;
};

#endif

