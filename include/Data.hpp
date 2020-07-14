#ifndef NeuralNetworkC_Data_H
#define NeuralNetworkC_Data_H

#include <vector>
#include "Matrix.hpp"

class Data
{
    private:
        std::vector<Matrix> trainingSet;
        std::vector<Matrix> testSet;

        Matrix nextRandomTrainingSet;
        Matrix nextRandomTestSet;

    public:
        Data();
        Data(std::vector<Matrix>, std::vector<Matrix>);
        void shuffle();
        Matrix getTrainingData();
        Matrix getTestData();

};
#endif //NeuralNetworkC_Data_H
