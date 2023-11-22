#ifndef WRITER_H
#define WRITER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>

class Writer {
public:

    Writer( const std::string& path );
    void write( float number );

private:
    void openFile();
    void closeFile();

    std::string path;
    std::ofstream fileToWrite;

};

#endif
