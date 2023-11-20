#ifndef ITASK_H
#define ITASK_H

#include <string>
#include "reader.h"
#include "writer.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <memory>

class ITask {
public:

    virtual float process( const std::vector< float >& data ) = 0;
    double getResult();
    virtual ~ITask() = default;

private:

};

// class TaskFactory {

// public:

// enum class TaskParam { sum, mult, sumSqr };
// static std::unique_ptr< ITask > createTask( TaskParam param );
// };

#endif
