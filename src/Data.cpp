#include "Data.hpp"
#include "Matrix.hpp"
#include <cstdlib>

Data::Data(std::vector<Matrix> trainingSet, std::vector<Matrix> testSet)
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

void Data::shuffle(){
    // generates random int between 0 and maxsize of trainingSet
    int randomInt = rand() % this->trainingSet.max_size();
    this->nextRandomTrainingSet = this->trainingSet.at(randomInt);
    this->nextRandomTestSet = this->testSet.at(randomInt);
}
