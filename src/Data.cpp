#include "Data.hpp"
#include "Matrix.hpp"

Data::Data(std::vector<Matrix> trainingSet, std::vector<Matrix> testSet)
{
    this->trainingSet = trainingSet;
    this->testSet = testSet;
};

std::vector<Matrix> Data::getTrainingData()
{
    return this->trainingSet;
}

std::vector<Matrix> Data::getTestData()
{
    return this->testSet;
}
