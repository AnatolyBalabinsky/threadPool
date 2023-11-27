#include <gtest/gtest.h>
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

