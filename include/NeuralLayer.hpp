#ifndef NeuralNetworkC_NeuralLayer_H
#define NeuralNetworkC_NeuralLayer_H

#include "Matrix.hpp"
#include "Activation/ActivationFunction.hpp"

class NeuralLayer
{

    public:
        NeuralLayer(unsigned int inputs, unsigned int units, ActivationFunction activation);
        Matrix layer_forward_propagation(Matrix &Activation_prev);
        Matrix layer_backward_propagation(Matrix &delta_Aprev);
        void updateParameters(double learningRate);

    private:
    	ActivationFunction activation;

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
