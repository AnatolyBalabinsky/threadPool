#include "task/taskSum.h"
#include "task/taskMult.h"
#include "task/taskSumSqr.h"

std::unique_ptr< ITask > TaskFactory::createTask( TaskType type ) {

    if( type == TaskType::sum ) {

        return std::make_unique< TaskSum >();

    } else if( type == TaskType::mult ) {

        return std::make_unique< TaskMult >();
    } else if( type == TaskType::sumSqr ) {

        return std::make_unique< TaskSumSqr >();
    } else {
        return nullptr;
    }

}
