#include "Data.hpp"
#include "Matrix.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>

Data::Data(Matrix trainingSet, Matrix testSet)
{
    this->trainingSet = trainingSet;
    this->testSet = testSet;
};

void Data::init(){

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

void Data::shuffle(){
    // generates random int between 0 and maxsize of trainingSet
    srand(time(0));//seed based on current time
    int randomInt = rand() % this->trainingSet.getRows(); //index based

    this->nextRandomTrainingSet = this->trainingSet.getRowAsNewMatrix(randomInt);
    this->nextRandomTestSet = this->testSet.getRowAsNewMatrix(randomInt);

}
