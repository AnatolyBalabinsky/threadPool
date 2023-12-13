#include "task/taskCalculate.h"

void TaskCalculate::setData( const std::vector< float >& data ) {
    this->data = data;
}

float TaskCalculate::getResult() const {
    return result;
}
