#ifndef NeuralNetworkC_Relu_H
#define NeuralNetworkC_Relu_H

#include "ActivationFunction.hpp"
#include "../Matrix.hpp"

typedef double (*activationtype)(double);

class Relu: public ActivationFunction 
{
    public:
       Matrix activation(Matrix &Z_Matrix) const;
       Matrix activation_derivative(Matrix &Z_Matrix) const;

    private:

       static double activate(double x);
       static double activate_derivative(double x);
       Matrix applyforAllElements(Matrix &Z_Matrix, activationtype) const;

};



#endif //NeuralNetworkC_Relu_H
