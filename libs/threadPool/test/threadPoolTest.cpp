#include <gtest/gtest.h>
#include "threadPool/threadPool.h"

TEST( ThreadPool, Thread100 ) {

    uint32_t countThreads = 3;
    std::string dirPath( "sourceData/testData_100" );

    auto t1 = std::chrono::system_clock::now();

    ThreadPool pool( countThreads, dirPath );
    pool.stop();

    auto t2 = std::chrono::system_clock::now();

    std::chrono::duration< double > time = t2 - t1;
    std::cout << time.count() << std::endl;

    // std::cout << pool.getResult() << std::endl;
    float trueRes100 = 1355.7854;
    // std::cout << trueRes100 << std::endl;

    ASSERT_NEAR( pool.getResult(), trueRes100, 1e-3 );
}

TEST( ThreadPool, DISABLED_Thread10 ) {

    uint32_t countThreads = 2;
    std::string dirPath( "sourceData/testData_10" );
    ThreadPool pool( countThreads, dirPath );
    pool.stop();

    // std::cout << pool.getResult() << std::endl;
    float trueRes100 = -15.1258;
    // std::cout << trueRes100 << std::endl;

    ASSERT_NEAR( pool.getResult(), trueRes100, 1e-3 );
}
