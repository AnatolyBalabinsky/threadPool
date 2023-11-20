#include <gtest/gtest.h>
#include "task/itask.h"
#include "task/taskMult.h"
#include "task/taskSum.h"
#include "task/taskSumSqr.h"
#include "task/reader.h"

TEST( TaskTest, Creating ) {


    TaskFactory taskFactory;
    TaskFactory::TaskType type = TaskFactory::TaskType::mult;
    ITask* it = new TaskMult;

    auto task = taskFactory.createTask( type );
    ASSERT_NE( task, nullptr );

    TaskMult* multPtr = dynamic_cast< TaskMult* >( task.get() );
    ASSERT_NE( multPtr, nullptr );

    TaskSum* sumPtr = dynamic_cast< TaskSum* >( task.get() );

    ASSERT_EQ( sumPtr, nullptr );

    TaskSumSqr* sumSqrPtr = dynamic_cast< TaskSumSqr* >( task.get() );

    ASSERT_EQ( sumSqrPtr, nullptr );
}


