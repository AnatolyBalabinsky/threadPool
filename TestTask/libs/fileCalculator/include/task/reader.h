#ifndef READER_H
#define READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <vector>

class Reader {
public:

    struct FileData {
        std::vector< float > fileData;
        uint32_t operType;
    };

    Reader( const std::string& path );
    FileData getFileData();

private:

    void openFile();
    void closeFile();

    std::string path;
    std::ifstream myFile;

};

#endif
