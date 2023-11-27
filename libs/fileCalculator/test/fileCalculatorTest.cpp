#include <gtest/gtest.h>
#include <ctime>

#include "reader/reader.h"
#include "fileCalculator/fileCalculator.h"

TEST( FileCalculatorTest, oneThread ) {

    FileCalculator calculator;
    auto result = calculator.oneThread( "sourceDat/testData_100" );
    ASSERT_NEAR( result, 1355.785, 1e-6 );
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

    double startTime = clock();
    calculator.oneThread( dirPath );
    double time1 = clock() - startTime;

    double startTime2 = clock();
    calculator.multipleThread( dirPath );
    double time2 = clock() - startTime2;

    std::cout << "time of oneThread: " << time1 << std::endl;
    std::cout << "time of multipleThread: " << time2 << std::endl;

}
