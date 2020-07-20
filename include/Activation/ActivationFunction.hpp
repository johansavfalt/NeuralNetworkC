#ifndef NeuralNetworkC_ActivationFunction_H
#define NeuralNetworkC_ActivationFunction_H

#include "Matrix.hpp"

class ActivationFunction
{

    public:
        virtual Matrix activation(Matrix &) const = 0;
        virtual Matrix activation_derivative(Matrix &) const = 0;

};



#endif //NeuralNetworkC_ActivationFunction_H

