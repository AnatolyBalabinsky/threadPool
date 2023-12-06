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
    std::chrono::duration< double > timeTwoThr;
    std::chrono::duration< double > timePool1;
    std::chrono::duration< double > timePool2;
    std::chrono::duration< double > timePool3;
    std::chrono::duration< double > timePool4;
    std::chrono::duration< double > timePool5;
    std::chrono::duration< double > timePool6;

    for( size_t i = 0; i < 1000; ++i ) {

// auto t1 = std::chrono::system_clock::now();
// calculator.oneThread( dirPath );

        auto t2 = std::chrono::system_clock::now();
        calculator.multipleThread( dirPath );
        auto t4 = std::chrono::system_clock::now();

        calculator.pool( 1, dirPath );
        auto t6 = std::chrono::system_clock::now();


// calculator.pool( 2, dirPath );
// auto t8 = std::chrono::system_clock::now();


// calculator.pool( 3, dirPath );
// auto t10 = std::chrono::system_clock::now();


// calculator.pool( 4, dirPath );
// auto t12 = std::chrono::system_clock::now();


// calculator.pool( 5, dirPath );
// auto t14 = std::chrono::system_clock::now();


// calculator.pool( 6, dirPath );
// auto t16 = std::chrono::system_clock::now();

        // timeOneThr += t2 - t1;
        timeTwoThr += t4 - t2;
        timePool1 += t6 - t4;
// timePool2 += t8 - t6;
// timePool3 += t10 - t8;
// timePool4 += t12 - t10;
// timePool5 += t14 - t12;
// timePool6 += t16 - t14;
    }

    // std::cout << "time of oneThread: " << timeOneThr.count() << std::endl;
    // std::cout << "time of multipleThread: " << timeTwoThr.count() << " procent " << timeTwoThr.count() / timeOneThr.count() * 100 << std::endl;
    // std::cout << "time of threadPool1: " << timePool1.count() << " procent " << timePool1.count() / timeOneThr.count() * 100 << std::endl;
    // std::cout << "time of threadPool2: " << timePool2.count() << " procent " << timePool2.count() / timeOneThr.count() * 100 << std::endl;
    // std::cout << "time of threadPool3: " << timePool3.count() << " procent " << timePool3.count() / timeOneThr.count() * 100 << std::endl;
    // std::cout << "time of threadPool4: " << timePool4.count() << " procent " << timePool4.count() / timeOneThr.count() * 100 << std::endl;
    // std::cout << "time of threadPool5: " << timePool5.count() << " procent " << timePool5.count() / timeOneThr.count() * 100 << std::endl;
    // std::cout << "time of threadPool6: " << timePool6.count() << " procent " << timePool6.count() / timeOneThr.count() * 100 << std::endl;

    std::cout << "time of multipleThread: " << timeTwoThr.count() << std::endl;
    std::cout << "time of threadPool1: " << timePool1.count() << " procent " << timePool1.count() / timeTwoThr.count() * 100 << std::endl;

}
