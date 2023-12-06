#include "task/taskMult.h"

// TaskMult::TaskMult( const std::vector< float >& data ) : data( data ) {
// }

void TaskMult::setData( const std::vector< float >& data ) {
    this->data = data;
}

void TaskMult::process() {

    result = 1;
    for( uint32_t i = 0; i != data.size(); i++ ) {
        result *= data[ i ];
    }
}

float TaskMult::getResult() const {
    return result;
}
