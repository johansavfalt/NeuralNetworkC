#ifndef NeuralNetworkC_NeuralLayer_H
#define NeuralNetworkC_NeuralLayer_H

#include "Matrix.hpp"
#include "Activation/ActivationFunction.hpp"
#include <memory>

class NeuralLayer
{

    public:
        NeuralLayer(unsigned int , unsigned int , const ActivationFunction&);
        std::shared_ptr<Matrix> layer_forward_propagation(std::shared_ptr<Matrix>);
        Matrix layer_backward_propagation(Matrix&);
        void updateParameters(double);
        void showWeights();

    private:
    	const ActivationFunction& activation;
        std::shared_ptr<Matrix> Activation_curr_1;
        std::shared_ptr<Matrix> Activation_prev;

        Matrix weights_momentum;
        std::shared_ptr<Matrix> weights;
        std::shared_ptr<Matrix> bias;
        Matrix Activation_curr;
        std::shared_ptr<Matrix> Z_curr;
        Matrix deltaWeights;
        Matrix deltaBias;
        Matrix deltaCurr;
        Matrix deltaCurr1;
        Matrix bias_momentum;
};



#endif //NeuralNetworkC_NeuralLayer_H
