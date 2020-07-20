#include "Data.hpp"
#include "Matrix.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>

// Sets Data trainingSet and TestSet
Data::Data(Matrix trainingSet, Matrix testSet)
{
    this->trainingSet = trainingSet;
    this->testSet = testSet;
};

Data::Data(){};

Matrix Data::getTrainingData()
{
    return this->nextRandomTrainingSet;
}

Matrix Data::getTestData()
{
    return this->nextRandomTestSet;
}

// shuffle function
//  create a random trainingexample with corresponding testexample
//  by generating a random number and using it to select the example
//
void Data::shuffle(){
    // generates random int between 0 and maxsize of trainingSet
    srand(time(0));//seed based on current time
    int randomInt = rand() % this->trainingSet.getRows(); //index based

    this->nextRandomTrainingSet = this->trainingSet.getRowAsNewMatrix(randomInt);
    this->nextRandomTestSet = this->testSet.getRowAsNewMatrix(randomInt);

}
