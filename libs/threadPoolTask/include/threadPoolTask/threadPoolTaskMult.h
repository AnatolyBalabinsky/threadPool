#ifndef THREADPOOLTASKMULT_H
#define THREADPOOLTASKMULT_H

#include "threadPoolTask/iThreadPoolTask.h"

class ThreadPoolTaskMult: public IThreadPoolTask< float > {
public:

    void process() override;

    void setFileData( const std::vector< float > data );
    std::future< float > getFutureResult() override;

    virtual ~ThreadPoolTaskMult() = default;

private:
    std::promise< float > result;
    std::vector< float > fileData;
};

#endif

