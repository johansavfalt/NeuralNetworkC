#ifndef NeuralNetworkC_Relu_H
#define NeuralNetworkC_Relu_H

#include "ActivationFunction.hpp"
#include "../Matrix.h"

typedef double (*activationtype)(double);

class Relu: public ActivationFunction 
{
    public:

       Matrix activation(Matrix &Z_Matrix);
       Matrix activation_derivative(Matrix &Z_Matrix);

    private:

       static double activate(double x);
       static double activate_derivative(double x);
       Matrix applyforAllElements(Matrix &Z_Matrix, activationtype);
};



#endif //NeuralNetworkC_Relu_H
