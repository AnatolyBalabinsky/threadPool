#include <filesystem>
#include "reader/reader.h"
#include "writer/writer.h"
#include "task/taskMult.h"
#include "task/taskSum.h"
#include "task/taskSumSqr.h"
#include "fileCalculator/fileCalculator.h"

int main( int argc, char* argv[] ) {

    FileCalculator calculator;

    if( *( argv[ 2 ] ) == '1' ) {

        calculator.oneThread( argv[ 1 ] );
    }

    if( *( argv[ 2 ] ) == '2' ) {

        std::cout << calculator.multipleThread( argv[ 1 ] ) << std::endl;
    }

	return 0;
}
