#ifndef NeuralNetworkC_Sigmoid_H
#define NeuralNetworkC_Sigmoid_H

#include "ActivationFunction.hpp"
#include "../Matrix.hpp"

typedef double (*activationtype)(double);

class Sigmoid: public ActivationFunction 
{
    public:
       Matrix activation(Matrix &);
       Matrix activation_derivative(Matrix &);

    private:

       static double activate(double x);
       static double activate_derivative(double x);
       Matrix applyforAllElements(Matrix &, double (*activationtype)(double)) const;
};



#endif //NeuralNetworkC_Sigmoid_H
