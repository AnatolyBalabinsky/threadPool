#ifndef TASKFACTORY_H
#define TASKFACTORY_H

#include "task/taskSum.h"
#include "task/taskMult.h"
#include "task/taskSumSqr.h"
#include "task/taskReadCalc.h"

class TaskFactory {

public:

    enum class TaskType { sum = 1, mult = 2, sumSqr = 3, readCalc = 4 };
    static std::unique_ptr< ITask > create( TaskType type ) {

        if( type == TaskType::sum ) {

            return std::make_unique< TaskSum >();

        } else if( type == TaskType::mult ) {

            return std::make_unique< TaskMult >();

        } else if( type == TaskType::sumSqr ) {

            return std::make_unique< TaskSumSqr >();

        } else if( type == TaskType::readCalc ) {

            return std::make_unique< TaskReadCalc >();

        } else {
            return nullptr;
        }
    }

};

#endif // TASKFACTORY_H
