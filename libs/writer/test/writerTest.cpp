#include <gtest/gtest.h>
#include "writer/writer.h"
#include <iostream>
#include <fstream>

TEST( WriterTest, Write ) {

    std::string filePath = "probe.txt";
    Writer writer( filePath );

    float inputNumber = 111.2;
    writer.write( inputNumber );

    std::ifstream testFile;
    testFile.open( "probe.txt" );

    float number = 0;
    testFile >> number;

    testFile.close();

    ASSERT_EQ( number, inputNumber );
}


