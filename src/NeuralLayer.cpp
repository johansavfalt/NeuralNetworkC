#include "../include/NeuralLayer.hpp"
#include "../include/Matrix.hpp"
#include "Activation/ActivationFunction.hpp"
#include <iostream>

NeuralLayer::NeuralLayer(unsigned int inputs, unsigned int units,
        const ActivationFunction &activation):

    activation(activation),
    Activation_curr(),
    Activation_prev(),
    weights(Matrix::random(inputs, units)),
    bias(Matrix(1, units)),
    Z_curr(),
    weights_momentum(inputs, units),
    deltaWeights(),
    deltaBias(1, units),
    deltaCurr(),
    deltaCurr1(),
    bias_momentum(1, units)


{
    bias.fillwith(1.0);

};

void NeuralLayer::showWeights(){
    this->weights.show();
};


Matrix NeuralLayer::layer_forward_propagation(Matrix &activation_prev)
{
    this->Activation_prev = activation_prev;
    this->Z_curr = this->Activation_prev.product(this->weights).plus(this->bias);
    this->Activation_curr = this->activation.activation(this->Z_curr);
    return this->Activation_curr;
};

Matrix NeuralLayer::layer_backward_propagation(Matrix &delta_Aprev)
{
    this->deltaWeights = this->Activation_prev.transpose().product(delta_Aprev);
    double sum = 0.0;
    for(int i = 0; i < delta_Aprev.getColumns(); i++){
        sum += delta_Aprev.getValue(0, i);
    }
    this->deltaBias.fillwith(sum);
    Matrix weightsTranspose = this->weights.transpose();
    this->deltaCurr = delta_Aprev.product(weightsTranspose);
    Matrix activationDelta = this->activation.activation_derivative(
            this->Activation_prev);
    this->deltaCurr1 = this->deltaCurr.hadamanproduct(activationDelta);
    return this->deltaCurr1;

};
void NeuralLayer::momentum(double beta){

    Matrix momentumMatrix = this->deltaWeights.timesConstant(1.0-beta);

    this->weights_momentum = this->weights_momentum.timesConstant(beta).plus(momentumMatrix);
    this->bias_momentum = this->bias_momentum.timesConstant(beta).plus(momentumMatrix);
}

void NeuralLayer::updateParameters(double &learningRate){

    this->momentum(0.8);

    Matrix momentumMatrix = this->weights_momentum.timesConstant(-learningRate);
    Matrix biasMatrix = this->bias_momentum.timesConstant(-learningRate);

    this->weights = this->weights.product(momentumMatrix);
    this->bias = this->bias.product(biasMatrix);
}
