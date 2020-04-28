#ifndef NeuralNetworkC_ActivationFunction_H
#define NeuralNetworkC_ActivationFunction_H

#include "../Matrix.h"

class ActivationFunction
{

    public:
       Matrix activation(Matrix &Z_Matrix);
       Matrix activation_derivative(Matrix &Z_Matrix);
};



#endif //NeuralNetworkC_ActivationFunction_H

