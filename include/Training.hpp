#ifndef NeuralNetworkC_Training_H
#define NeuralNetworkC_Training_H
#include "Matrix.hpp"

class Training
{

    private:

    public:
        static Matrix compute_cross_entropy_loss(
                Matrix &data, Matrix &test, bool derivative);
        static Matrix cross_entropy_loss(
                Matrix &predictDistribution, Matrix &trueDistribution);


};
#endif //NeuralNetworkC_Training_H
