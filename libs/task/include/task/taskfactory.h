#ifndef TASKFACTORY_H
#define TASKFACTORY_H

#include "task/taskSum.h"
#include "task/taskMult.h"
#include "task/taskSumSqr.h"

class TaskFactory {

public:

    enum class TaskType { sum = 1, mult = 2, sumSqr = 3 };
    static std::unique_ptr< ITask > create( TaskType type ) {

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
};


#endif // TASKFACTORY_H
