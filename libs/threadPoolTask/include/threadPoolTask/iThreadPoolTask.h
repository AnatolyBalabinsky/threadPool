#ifndef ITASK_H
#define ITASK_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <memory>

class IThreadPoolTask {
public:

    virtual void process() = 0;
    virtual ~IThreadPoolTask() = default;

protected:
    IThreadPoolTask() = default;

private:

};

class ThreadPoolTaskFactory {

public:

    enum class TaskType { sum, mult, sumSqr };
    static std::unique_ptr< IThreadPoolTask > createTask( TaskType param );
};

#endif
