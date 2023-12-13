#ifndef TESTTASK_H
#define TESTTASK_H

#include <iostream>
#include <vector>
#include <numeric>

#include "task/itask.h"

class TestTask: public ITask {
public:
    void process() {

        ( *this->result ) = std::accumulate( data.begin(), data.end(), 0.0f );
    }

    void setData( std::vector< float > data ) {
        this->data = data;
    }

    void setResult( float* result ) {
        this->result = result;
    }

private:
    std::vector< float > data;
    float* result;
};

class TestTask2: public ITask {
public:

    void process() {

        float result = 1;

        for( int i = 0; i != data.size(); i++ ) {
            result *= data[ i ];
        }

        ( *this->result ) = result;
    }

    void setData( std::vector< float > data ) {
        this->data = data;
    }

    void setResult( float* result ) {
        this->result = result;
    }

private:
    std::vector< float > data;
    float* result;
};

#endif // TESTTASK_H
