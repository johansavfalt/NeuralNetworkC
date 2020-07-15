#include "Data.hpp"
#include "Matrix.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

Data::Data(Matrix trainingSet, Matrix testSet)
{
    this->trainingSet = trainingSet;
    this->testSet = testSet;
};

void Data::init(){
    this->nextRandomTestSet = Matrix(1, this->testSet.getColumns());
    this->nextRandomTrainingSet = Matrix(1, this->trainingSet.getColumns());

    for(auto matrixRow: this->trainingSet.getData()){
        //fillup matrix with the trainingset Data
        //TODO or i just choose a rendom row of the matrixes and create a matrix of the row?

    };


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
    int randomInt = rand() % this->trainingSet.getRows();
    //something wrong on this next line
    //std::cout << randomInt << std::endl;
    //std::cout << this->trainingSet.getRows() << std::endl;

    //this->nextRandomTrainingSet = this->trainingSet.at(randomInt);
    //this->nextRandomTestSet = this->testSet.at(randomInt);
}
