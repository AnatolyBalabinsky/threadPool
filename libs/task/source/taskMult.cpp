#include "task/taskMult.h"

void TaskMult::process() {

    result = 1;
    for( uint32_t i = 0; i != data.size(); i++ ) {
        result *= data[ i ];
    }
}
