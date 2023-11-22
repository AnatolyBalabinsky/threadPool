#include "task/taskSum.h"

float TaskSum::process( const std::vector< float >& data ) {
    float result = 0;
    for( uint32_t i = 0; i != data.size(); i++ ) {
        result += data[ i ];
    }
    return result;
}
