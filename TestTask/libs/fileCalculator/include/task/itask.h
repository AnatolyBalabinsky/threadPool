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

protected:
    ITask() = default;

private:

};

class TaskFactory {

public:

    enum class TaskType { sum, mult, sumSqr };
    static std::unique_ptr< ITask > createTask( TaskType param );
};

#endif
