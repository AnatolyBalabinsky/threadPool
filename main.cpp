#include "printer/printer.h"
#include <filesystem>
#include "reader/reader.h"
#include "writer/writer.h"
#include "task/taskMult.h"
#include "task/taskSum.h"
#include "task/taskSumSqr.h"

int main( int argc, char* argv[] ) {

    std::filesystem::path directory( argv[ 1 ] );

    if( !std::filesystem::exists( directory ) ) {
        std::cout << "Директория не существует" << std::endl;
        return 0;
    }

    std::filesystem::directory_iterator begin( directory );
    std::filesystem::directory_iterator end;

    float result = 0;
    for( ; begin != end; ++begin ) {

        if( begin->path().filename() == "out.dat" ) {
            continue;
        }

        // Вывод имени файла
        std::cout << begin->path().filename() << std::endl;

        Reader reader( begin->path() );
        Reader::FileData fd = reader.getFileData();

        TaskFactory factory;
        TaskFactory::TaskType type;
        if( fd.operType == 1 ) {
            type = TaskFactory::TaskType::sum;
        }
        if( fd.operType == 2 ) {
            type = TaskFactory::TaskType::mult;
        }
        if( fd.operType == 3 ) {
            type = TaskFactory::TaskType::sumSqr;
        }

        auto task = factory.createTask( type );
        std::cerr << "data size: " << fd.fileData.size() << std::endl;
        auto currRes = task->process( fd.fileData );
        std::cerr << "currRes: " << currRes << std::endl;
        result += currRes;
        std::cerr << "result: " << result << std::endl;

    }

    std::cout << std::fixed << std::setprecision( 4 ) << result << std::endl;

    Writer writer( "myOut.dat" );
    writer.write( result );

	return 0;
}
