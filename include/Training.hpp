#ifndef NeuralNetworkC_Matrix_H
#define NeuralNetworkC_Matrix_H
#include "Matrix.hpp"

class Training
{

    private:

    public:
        Matrix compute_cross_entropy_loss(
                Matrix &data, Matrix &test, boolean derivative);
        Matrix cross_entropy_loss(
                Matrix &predictDistribution, Matrix &trueDistribution);


};
#endif //NeuralNetworkC_Matrix_H
