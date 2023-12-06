#ifndef ITASK_H
#define ITASK_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <memory>
#include <future>

template < typename ReturnType >
class IThreadPoolTask {
public:

    virtual void process() = 0;
    virtual std::future< ReturnType > getFutureResult() = 0;
    virtual ~IThreadPoolTask() = default;

protected:
    IThreadPoolTask() = default;

private:

};

class ThreadPoolTaskFactory {

public:

    enum class TaskType { sum, mult, sumSqr };
    template < typename ReturnType >
    static std::unique_ptr< IThreadPoolTask< ReturnType > > createTask( TaskType param );
};

#endif
