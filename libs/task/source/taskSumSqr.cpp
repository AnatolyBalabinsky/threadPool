#include "task/taskSumSqr.h"

// TaskSumSqr::TaskSumSqr( const std::vector< float >& data ) : data( data ) {
// }

void TaskSumSqr::setData( const std::vector< float >& data ) {
    this->data = data;
}

void TaskSumSqr::process() {

    for( uint32_t i = 0; i != data.size(); i++ ) {
        result += data[ i ] * data[ i ];
    }

}

float TaskSumSqr::getResult() const {
    return result;
}

