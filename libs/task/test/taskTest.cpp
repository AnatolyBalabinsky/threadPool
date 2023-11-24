#include <gtest/gtest.h>
#include "task/itask.h"
#include "task/taskMult.h"
#include "task/taskSum.h"
#include "task/taskSumSqr.h"
#include "reader/reader.h"

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

TEST( TaskTest, TaskMult ) {

    TaskFactory taskFactory;
    TaskFactory::TaskType type = TaskFactory::TaskType::mult;
    auto task = taskFactory.createTask( type );

    std::vector< float > data = { 1.2, 1.4, 5.5, 2, 2.65 };
    float result =  task->process( data );
    float expect = 48.972;

    ASSERT_NEAR( result,  expect, 10e-6 );

}

TEST( TaskTest, TaskSum ) {

    TaskFactory taskFactory;
    TaskFactory::TaskType type = TaskFactory::TaskType::sum;
    auto task = taskFactory.createTask( type );

    std::vector< float > data = { 1.2, 1.4, 5.5, 2, 7.65 };
    float result = task->process( data );
    float expect = 17.75;

    ASSERT_NEAR( result,  expect, 10e-6 );

}

TEST( TaskTest, TaskSumSqr ) {

    TaskFactory taskFactory;
    TaskFactory::TaskType type = TaskFactory::TaskType::sumSqr;
    auto task = taskFactory.createTask( type );

    std::vector< float > data = { 1.2, 1.4, 5.5, 2, 7.6 };
    float result = task->process( data );

    float expect = 95.41;
    ASSERT_NEAR( result,  expect, 10e-6 );

}
