#include <gtest/gtest.h>
#include <ctime>

#include "fileCalculator/fileCalculator.h"

TEST( FileCalculatorTest, oneThread ) {

    FileCalculator calculator;
    auto result = calculator.oneThread( "sourceDat/testData_100" );
    ASSERT_NEAR( result, 1355.785, 1e-3 );
}

TEST( FileCalculatorTest, multipleThread ) {

    FileCalculator calculator;
    std::string dirPath( "sourceDat/testData_100" );

    auto resOne = calculator.oneThread( dirPath );
    auto resMultiple = calculator.multipleThread( dirPath );

    ASSERT_EQ( resMultiple, resOne );

}

TEST( FileCalculatorTest, pool ) {

    FileCalculator calculator;

    std::string dirPath( "sourceDat/testData_100" );
    uint32_t threadCount = 4;

    auto resOne = calculator.oneThread( dirPath );
    auto resPool = calculator.pool( threadCount, dirPath );

    ASSERT_EQ( resPool, resOne );

}

TEST( FileCalculatorTest, DISABLED_TimeComparing ) {

    FileCalculator calculator;

    std::string dirPath( "sourceDat/testData_100" );
    uint32_t threadCount;

    std::chrono::duration< double > timeOneThr;
    std::chrono::duration< double > timeMultThr;

    std::chrono::duration< double > timePool2;
    std::chrono::duration< double > timePool3;
    std::chrono::duration< double > timePool4;

    for( size_t i = 0; i < 1000; ++i ) {

        auto t1 = std::chrono::system_clock::now();
        calculator.oneThread( dirPath );

        auto t2 = std::chrono::system_clock::now();
        calculator.multipleThread( dirPath );
        auto t3 = std::chrono::system_clock::now();

        threadCount = 2;
        auto t4 = std::chrono::system_clock::now();
        calculator.pool( threadCount, dirPath );
        auto t5 = std::chrono::system_clock::now();

        threadCount = 3;
        auto t6 = std::chrono::system_clock::now();
        calculator.pool( threadCount, dirPath );
        auto t7 = std::chrono::system_clock::now();

        threadCount = std::thread::hardware_concurrency();
        auto t8 = std::chrono::system_clock::now();
        calculator.pool( threadCount, dirPath );
        auto t9 = std::chrono::system_clock::now();

        timeOneThr += t2 - t1;
        timeMultThr += t3 - t2;

        timePool2 += t5 - t4;
        timePool3 += t7 - t6;
        timePool4 += t9 - t8;

    }

    std::cout << "time of oneThread: " << timeOneThr.count() << std::endl;
    std::cout << "time of multipleThread: " << timeMultThr.count() << " procent " << timeMultThr.count() / timeOneThr.count() * 100 << std::endl;
    std::cout << "time of pool2: " << timePool2.count() << " procent " << timePool2.count() / timeOneThr.count() * 100 << std::endl;
    std::cout << "time of pool3: " << timePool3.count() << " procent " << timePool3.count() / timeOneThr.count() * 100 << std::endl;
    std::cout << "time of pool4: " << timePool4.count() << " procent " << timePool4.count() / timeOneThr.count() * 100 << std::endl;

}
