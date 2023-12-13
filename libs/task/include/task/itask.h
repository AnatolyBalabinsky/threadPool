#ifndef ITASK_H
#define ITASK_H

class ITask {
public:

    virtual void process() = 0;
    virtual ~ITask() = default;

};


#endif
