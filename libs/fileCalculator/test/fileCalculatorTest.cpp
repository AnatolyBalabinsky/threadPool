#include <gtest/gtest.h>
#include <ctime>

#include "reader/reader.h"
#include "fileCalculator/fileCalculator.h"

TEST( FileCalculatorTest, oneThread ) {

    FileCalculator calculator;
    auto result = calculator.oneThread( "sourceDat/testData_100" );
    ASSERT_NEAR( result, 1355.785, 1e-3 );
}

TEST( FileCalculatorTest, multipleThread ) {

    FileCalculator calculator;
    auto result = calculator.multipleThread( "sourceDat/testData_100" );
    ASSERT_NEAR( result, 1355.785, 1e-3 );

}

TEST( FileCalculatorTest, ResultComparing ) {

    FileCalculator calculator;

    std::string dirPath( "sourceDat/testData_100" );

    auto resMultiple = calculator.multipleThread( dirPath );
    auto resOne = calculator.oneThread( dirPath );

    ASSERT_EQ( resMultiple, resOne );

}

TEST( FileCalculatorTest, TimeComparing ) {

    FileCalculator calculator;

    std::string dirPath( "sourceDat/testData_100" );

    std::chrono::duration< double > timeOneThr;
    std::chrono::duration< double > timeMultThr;

    for( size_t i = 0; i < 1000; ++i ) {

        auto t1 = std::chrono::system_clock::now();
        calculator.oneThread( dirPath );

        auto t2 = std::chrono::system_clock::now();
        calculator.multipleThread( dirPath );
        auto t3 = std::chrono::system_clock::now();

        timeOneThr += t2 - t1;
        timeMultThr += t3 - t2;

    }

    std::cout << "time of oneThread: " << timeOneThr.count() << std::endl;
    std::cout << "time of multipleThread: " << timeMultThr.count() << " procent " << timeMultThr.count() / timeOneThr.count() * 100 << std::endl;

}
