#ifndef NeuralNetworkC_Data_H
#define NeuralNetworkC_Data_H

#include <vector>
#include "Matrix.hpp"

class Data
{
    private:
        Matrix trainingSet;
        Matrix testSet;

        Matrix nextRandomTrainingSet;
        Matrix nextRandomTestSet;

    public:
        Data();
        Data(Matrix, Matrix);
        void shuffle();
        Matrix getTrainingData();
        Matrix getTestData();

};
#endif //NeuralNetworkC_Data_H
