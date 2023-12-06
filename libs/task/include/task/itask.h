#ifndef ITASK_H
#define ITASK_H

#include <memory>

class ITask {
public:

    virtual void process() = 0;
    virtual ~ITask() = default;

protected:
    ITask() = default;

private:

};


#endif
