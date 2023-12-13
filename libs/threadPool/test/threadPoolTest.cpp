#include <gtest/gtest.h>
#include <filesystem>

#include "threadPool/threadPool.h"
#include "test/testTask.h"
#include "task/taskfactory.h"

TEST( ThreadPool, OneThread ) {

    uint32_t countThreads = 1;

    TestTask task;

    std::vector< float > data = { 1.2, 2.5, 5.5, 6.6 };
    float result = 0;

    task.setData( data );
    task.setResult( &result );

    std::unique_ptr< ITask > taskU = std::make_unique< TestTask >( task );

    ThreadPool pool( countThreads );

    pool.addTask( std::move( taskU ) );
    pool.stop();

    ASSERT_NEAR( result, 15.8, 1e-2 );

}

TEST( ThreadPool, fourThreads ) {

    uint32_t countThreads = 4;

    TestTask task;

    std::vector< float > data = { 1.2, 2.5, 5.5, 6.6 };
    std::vector< float > results = { 0, 0, 0, 0, 0, 0 };

    ThreadPool pool( countThreads );

    for( int i = 0; i != 6; i++ ) {

        task.setData( data );
        task.setResult( &results[ i ] );
        std::unique_ptr< ITask > taskU = std::make_unique< TestTask >( task );
        pool.addTask( std::move( taskU ) );

    }

    pool.stop();

    float result = std::accumulate( results.begin(), results.end(), 0.0f );
    ASSERT_NEAR( result, 94.8, 1e-2 );

}

TEST( ThreadPool, fourThreads_differentTasks ) {

    uint32_t countThreads = 4;

    TestTask task1;
    TestTask2 task2;

    std::vector< float > data = { 1.2, 2.5, 5.5, 6.6 };
    std::vector< float > results = { 0, 0, 0, 0, 0, 0 };

    ThreadPool pool( countThreads );

    for( int i = 0; i != 3; i++ ) {

        task1.setData( data );
        task1.setResult( &results[ i ] );
        std::unique_ptr< ITask > taskU = std::make_unique< TestTask >( task1 );
        pool.addTask( std::move( taskU ) );

    }

    for( int i = 3; i != 6; i++ ) {

        task2.setData( data );
        task2.setResult( &results[ i ] );
        std::unique_ptr< ITask > taskU = std::make_unique< TestTask2 >( task2 );
        pool.addTask( std::move( taskU ) );

    }

    pool.stop();

    float result = std::accumulate( results.begin(), results.end(), 0.0f );
    ASSERT_NEAR( result, 374.1, 1e-2 );

}

