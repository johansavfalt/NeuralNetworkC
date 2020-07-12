#ifndef NeuralNetworkC_Training_H
#define NeuralNetworkC_Training_H

#include "NeuralLayer.hpp"
#include "Matrix.hpp"
#include "Data.hpp"
#include <vector>

class Training
{

    private:
        int printResult;
        int epochs;
        int learningRate;
        Data DataSet;
        std::vector<NeuralLayer> NeuralNetwork;

    public:
        //TODO should accept NeuralNetwork class as first parameter
        Training(std::vector<NeuralLayer>, double learningRate, int epochs,
                Data  DataSet, int printResult);

        static Matrix compute_cross_entropy_loss(
                Matrix &data, Matrix &test, bool derivative);

        static Matrix cross_entropy_loss(
                Matrix &predictDistribution, Matrix &trueDistribution);

        void train();

        Matrix forwardPropagation(std::vector<Matrix> &);


};
#endif //NeuralNetworkC_Training_H
