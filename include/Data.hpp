#ifndef NeuralNetworkC_Data_H
#define NeuralNetworkC_Data_H

#include <vector>
#include "Matrix.hpp"

class Data
{
    private:
        std::vector<Matrix> trainingSet;
        std::vector<Matrix> testSet;
    public:
        Data(std::vector<Matrix>, std::vector<Matrix>);
        std::vector<Matrix> getTrainingData();
        std::vector<Matrix> getTestData();

};
#endif //NeuralNetworkC_Data_H
