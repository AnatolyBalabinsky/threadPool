#include "reader/reader.h"

Reader::Reader( const std::string& path ) : path( path ) {

}

void Reader::openFile() {
    myFile.open( path );
    if( !myFile.is_open() ) {

        throw std::runtime_error( "Can't open " + path );

    }
}

void Reader::closeFile() {
    myFile.close();
}

Reader::FileData Reader::getFileData() {

    openFile();

    FileData fData;

    myFile >> fData.operType;

    float number = 0;

    while( myFile >> number ) {

        fData.fileData.push_back( number );

    }

    closeFile();
    return fData;
}
