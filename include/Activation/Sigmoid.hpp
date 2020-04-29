#ifndef NeuralNetworkC_Sigmoid_H
#define NeuralNetworkC_Sigmoid_H

#include "ActivationFunction.hpp"
#include "../Matrix.hpp"

typedef double (*activationtype)(double);

class Sigmoid: public ActivationFunction 
{
    public:
       Matrix activation(Matrix &Z_Matrix);
       Matrix activation_derivative(Matrix &Z_Matrix);

    private:

       static double activate(double x);
       static double activate_derivative(double x);
       Matrix applyforAllElements(Matrix &Z_Matrix, activationtype);
};



#endif //NeuralNetworkC_Sigmoid_H
