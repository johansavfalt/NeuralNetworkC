#ifndef NeuralNetworkC_NeuralLayer_H
#define NeuralNetworkC_NeuralLayer_H

#include "Matrix.hpp"
#include "Activation/ActivationFunction.hpp"
#include <memory>

class NeuralLayer
{

    public:
        NeuralLayer(unsigned int , unsigned int , const ActivationFunction &);
        Matrix layer_forward_propagation(Matrix &);
        Matrix layer_backward_propagation(Matrix &);
        void updateParameters(double);
        void showWeights();

    private:
    	const ActivationFunction &activation;

        Matrix Activation_curr;
        Matrix Activation_prev;

        Matrix weights;
        Matrix bias;
        Matrix Z_curr;

        Matrix weights_momentum;
        Matrix deltaWeights;
        Matrix deltaBias;
        Matrix deltaCurr;
        Matrix deltaCurr1;
        Matrix bias_momentum;
};



#endif //NeuralNetworkC_NeuralLayer_H
