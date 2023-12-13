#include <filesystem>

#include "task/taskfactory.h"
#include "reader/reader.h"

void TaskReadCalc::setFilePath(const std::string &filePath ) {
    this->filePath = filePath;
}

void TaskReadCalc::setResult( float* result ) {
    this->result = result;
}

float TaskReadCalc::getFileResult(const std::string &filePath ) {

    Reader reader( filePath );
    Reader::FileData fd = reader.getFileData();

    auto task = TaskFactory::create( static_cast< TaskFactory::TaskType >( fd.operType ) );
    auto taskCalc = dynamic_cast< TaskCalculate* >(  task.get() );

    taskCalc->setData( fd.fileData );
    taskCalc->process();

    return taskCalc->getResult();
}

void TaskReadCalc::getFileResultWrap(const std::string &filePath, float* result ) {
    *result = getFileResult( filePath );
}

void TaskReadCalc::process() {

    getFileResultWrap( filePath, result );

}


