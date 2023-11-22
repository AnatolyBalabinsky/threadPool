#include <gtest/gtest.h>
#include "reader/reader.h"

TEST( ReaderTest, Creating ) {

    std::string filePath = "data/uprobe.txt";
    Reader testedObject( filePath );

    try {

        testedObject.getFileData();

    } catch( std::exception& e ) {

        ASSERT_STREQ( e.what(), "Can't open data/uprobe.txt" );

    }

}

TEST( ReaderTest, readingDouble ) {

    Reader reader( "data/probe.txt" );

    Reader::FileData data = reader.getFileData();
    std::vector< float > trueData = { 1.155, 1.255, 1.11 };

    for( int i = 0; i != data.fileData.size(); i++ ) {

        ASSERT_EQ( data.fileData [ i ], trueData[ i ] );

    }

    ASSERT_EQ( data.operType, 1 );

}

