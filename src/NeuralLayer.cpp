#include "../include/NeuralLayer.hpp"
#include "../include/Matrix.hpp"
#include "Activation/ActivationFunction.hpp"

NeuralLayer::NeuralLayer(unsigned int inputs,
        unsigned int units,
        ActivationFunction *activation
        ):

    activation(),
    weights(Matrix::random(inputs, units)),
    bias(1, units),
    deltaBias(1, units),
    weights_momentum(inputs, units),
    bias_momentum(1, units),
    Activation_prev(),
    Z_curr(),
    Activation_curr()

{
    bias.fillwith(1.0);

};


Matrix NeuralLayer::layer_forward_propagation(Matrix &Activation_prev)
{
    this->Activation_prev = Activation_prev;
    this->Z_curr = this->Activation_prev.product(this->weights).plus(this->bias);
    this->Activation_curr = this->activation->activation(this->Z_curr);
    return this->Activation_curr;
};
