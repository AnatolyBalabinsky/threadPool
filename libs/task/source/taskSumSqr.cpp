#include "task/taskSumSqr.h"

float TaskSumSqr::process( const std::vector< float >& data ) {
    float result = 0;
    for( uint32_t i = 0; i != data.size(); i++ ) {
        result += data[ i ] * data[ i ];
    }
    return result;
}
