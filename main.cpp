#include <filesystem>
#include "fileCalculator/fileCalculator.h"

int main( int argc, char* argv[] ) {

    FileCalculator calculator;

    if( *( argv[ 2 ] ) == '1' ) {

        calculator.oneThread( argv[ 1 ] );
    }

    if( *( argv[ 2 ] ) == '2' ) {

        std::cout << calculator.multipleThread( argv[ 1 ] ) << std::endl;
    }

    if( *( argv[ 2 ] ) == '3' ) {

        uint32_t count = std::thread::hardware_concurrency();
        std::cout << calculator.pool( count, argv[ 1 ] ) << std::endl;

    }

	return 0;
}
