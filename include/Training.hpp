#ifndef NeuralNetworkC_Training_H
#define NeuralNetworkC_Training_H

#include "NeuralNetwork.hpp"
#include "Matrix.hpp"
#include "Data.hpp"
#include <vector>

class Training
{

    private:
        int printResult;
        int epochs;
        double learningRate;

        Data DataSet;
        NeuralNetwork NeuralLayers;

    public:
        Training(NeuralNetwork NeuralLayers, double learningRate, int epochs,
                Data  DataSet, int printResult);

        static Matrix compute_cross_entropy_loss(
                Matrix &data, Matrix &test, bool derivative);

        static Matrix cross_entropy_loss(
                Matrix &predictDistribution, Matrix &trueDistribution);

        void train();
        void updateParameters();

        Matrix forwardPropagation(Matrix);
        Matrix backwardPropagation(Matrix);



};
#endif //NeuralNetworkC_Training_H
