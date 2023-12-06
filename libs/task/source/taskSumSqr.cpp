#include "task/taskSumSqr.h"

void TaskSumSqr::process() {

    for( uint32_t i = 0; i != data.size(); i++ ) {
        result += data[ i ] * data[ i ];
    }

}

