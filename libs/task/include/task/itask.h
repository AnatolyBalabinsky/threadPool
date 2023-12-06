#ifndef ITASK_H
#define ITASK_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <memory>

class ITask {
public:

    virtual float process( const std::vector< float >& data ) = 0;
    virtual ~ITask() = default;

protected:
    ITask() = default;

private:

};

class TaskFactory {

public:

    enum class TaskType { sum = 1, mult = 2, sumSqr = 3 };
    static std::unique_ptr< ITask > createTask( TaskType param );
};

#endif
