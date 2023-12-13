#include <gtest/gtest.h>

#include "reader/reader.h"
#include "task/taskfactory.h"

TEST( TaskTest, Creating ) {

    TaskFactory taskFactory;
    TaskFactory::TaskType type = TaskFactory::TaskType::mult;
    ITask* it = new TaskMult;

    auto task = taskFactory.create( type );
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
    auto task = taskFactory.create( type );

    std::vector< float > data = { 1.2, 1.4, 5.5, 2, 2.65 };

    dynamic_cast< TaskMult* >( task.get() )->setData( data );

    task->process();

    float result = dynamic_cast< TaskMult* >( task.get() )->getResult();

    float expect = 48.972;

    ASSERT_NEAR( result,  expect, 10e-6 );

}

TEST( TaskTest, TaskSum ) {

    TaskFactory taskFactory;
    TaskFactory::TaskType type = TaskFactory::TaskType::sum;
    auto task = taskFactory.create( type );

    std::vector< float > data = { 1.2, 1.4, 5.5, 2, 7.65 };

    dynamic_cast< TaskSum* >( task.get() )->setData( data );

    task->process();

    float result = dynamic_cast< TaskSum* >( task.get() )->getResult();
    float expect = 17.75;

    ASSERT_NEAR( result,  expect, 10e-6 );

}

TEST( TaskTest, TaskSumSqr ) {

    TaskFactory taskFactory;
    TaskFactory::TaskType type = TaskFactory::TaskType::sumSqr;
    auto task = taskFactory.create( type );

    std::vector< float > data = { 1.2, 1.4, 5.5, 2, 7.6 };

    dynamic_cast< TaskSumSqr* >( task.get() )->setData( data );

    task->process();

    float result = dynamic_cast< TaskSumSqr* >( task.get() )->getResult();
    float expect = 95.41;

    ASSERT_NEAR( result,  expect, 10e-6 );

}
