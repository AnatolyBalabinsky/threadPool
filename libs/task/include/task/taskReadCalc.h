#ifndef TASKREADCALC_H
#define TASKREADCALC_H

#include <vector>
#include <string>

#include "task/itask.h"

class TaskReadCalc: public ITask {
public:

    void process() override;

    float getFileResult( const std::string& filePath );
    void getFileResultWhrap( const std::string& filePath, float* result );

    void setFilePath( const std::string& filePath );
    void setResult( float* result );

private:
    float* result;
    std::string filePath;

};

#endif // TASKREADCALC_H
