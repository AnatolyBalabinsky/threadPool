#include "task/taskSum.h"

// TaskSum::TaskSum( const std::vector< float >& data ) : data( data ) {
// }

void TaskSum::setData( const std::vector< float >& data ) {
    this->data = data;
}

void TaskSum::process() {

    for( uint32_t i = 0; i != data.size(); i++ ) {
        result += data[ i ];
    }

}

float TaskSum::getResult() const {
    return result;
}

