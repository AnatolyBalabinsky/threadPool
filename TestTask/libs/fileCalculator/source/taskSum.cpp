#include "taskSum.h"

float TaskSum::process( const std::vector< float >& data ) {
    double result = 0;
    for( uint32_t i = 0; i != data.size(); i++ ) {
        result += data[ i ];
    }
    return result;
}
