#include "task/taskSum.h"

void TaskSum::process() {

    for( uint32_t i = 0; i != data.size(); i++ ) {
        result += data[ i ];
    }

}

