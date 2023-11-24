#include "writer/writer.h"

Writer::Writer( const std::string& path ) : path( path ) {

}

void Writer::openFile() {
    fileToWrite.open( path );
}

void Writer::closeFile() {
    fileToWrite.close();
}

void Writer::write( float number ) {
    openFile();
    fileToWrite << number;
    closeFile();
}
