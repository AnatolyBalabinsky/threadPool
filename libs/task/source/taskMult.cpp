#include "task/taskMult.h"

float TaskMult::process( const std::vector< float >& data ) {

    float result = 1;
    for( uint32_t i = 0; i != data.size(); i++ ) {
        result *= data[ i ];
    }
    return result;
}
