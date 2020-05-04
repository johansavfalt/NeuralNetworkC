#ifndef NeuralNetworkC_NeuralLayer_H
#define NeuralNetworkC_NeuralLayer_H

#include "Matrix.hpp"
#include "Activation/ActivationFunction.hpp"

class NeuralLayer
{

    public:
        NeuralLayer(unsigned int , unsigned int , const ActivationFunction&);
        Matrix layer_forward_propagation(Matrix&);
        Matrix layer_backward_propagation(Matrix&);
        void updateParameters(double);

    private:
    	const ActivationFunction& activation;

        Matrix weights_momentum;
        Matrix weights;
        Matrix bias;
		Matrix Activation_prev;
        Matrix Activation_curr;
        Matrix Z_curr;
        Matrix deltaWeights;
        Matrix deltaBias;
        Matrix deltaCurr;
        Matrix deltaCurr1;
        Matrix bias_momentum;
};



#endif //NeuralNetworkC_NeuralLayer_H
