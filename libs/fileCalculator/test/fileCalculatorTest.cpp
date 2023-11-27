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

    auto t1 = std::chrono::system_clock::now();
    calculator.oneThread( dirPath );
    auto t2 = std::chrono::system_clock::now();

    auto t3 = std::chrono::system_clock::now();
    calculator.multipleThread( dirPath );
    auto t4 = std::chrono::system_clock::now();

    std::chrono::duration< double > time1 = t2 - t1;
    std::chrono::duration< double > time2 = t4 - t3;

    std::cout << "time of oneThread: " << time1.count() << std::endl;
    std::cout << "time of multipleThread: " << time2.count() << std::endl;

}
