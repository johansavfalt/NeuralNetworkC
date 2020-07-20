#ifndef NeuralNetworkC_Training_H
#define NeuralNetworkC_Training_H

#include "Matrix.hpp"
#include "Data.hpp"
#include <vector>
#include "NeuralLayer.hpp"

class Training
{

    private:
        int printResult;
        int epochs;
        double learningRate;

        Data DataSet;

    public:
        Training(double learningRate, int epochs,
                Data  DataSet, int printResult);

        static Matrix compute_cross_entropy_loss(
                Matrix &data, Matrix &test, bool derivative);

        static Matrix cross_entropy_loss(
                Matrix &predictDistribution, Matrix &trueDistribution);

        void train(std::vector<NeuralLayer> &);
        void updateParameters(std::vector<NeuralLayer> &);

        Matrix forwardPropagation(std::vector<NeuralLayer> &, Matrix data);
        Matrix backwardPropagation(std::vector<NeuralLayer> &, Matrix data);



};
#endif //NeuralNetworkC_Training_H
