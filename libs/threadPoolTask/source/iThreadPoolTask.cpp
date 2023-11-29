#include "threadPoolTask/iThreadPoolTask.h"
#include "threadPoolTask/threadPoolTaskMult.h"
#include "threadPoolTask/threadPoolTaskSum.h"
#include "threadPoolTask/threadPoolTaskSumSqr.h"

std::unique_ptr< IThreadPoolTask > ThreadPoolTaskFactory::createTask( TaskType type ) {

    if( type == TaskType::sum ) {

        return std::make_unique< ThreadPoolTaskSum >();

    } else if( type == TaskType::mult ) {

        return std::make_unique< ThreadPoolTaskMult >();
    } else if( type == TaskType::sumSqr ) {

        return std::make_unique< ThreadPoolTaskSumSqr >();
    } else {
        return nullptr;
    }

}
