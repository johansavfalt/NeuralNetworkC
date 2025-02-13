#include "NeuralLayer.hpp"
#include "Matrix.hpp"
#include "Activation/ActivationFunction.hpp"
#include <iostream>

// NeuralLayer class
// Creates a "NeuralLayer" which consist of Matrices and operations on them
// Neurallayers instances together create a network of layers (NeuralNetwork)
// Example:
//  NeuralLayer NeuralLayer1(2, 4, Relu());

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

// layer_forward_propagation
// performec layer_forward_propagation on the weights and biases matrices of
//
Matrix NeuralLayer::layer_forward_propagation(Matrix &activation_prev)
{
    this->Activation_prev = activation_prev;
    this->Z_curr = this->Activation_prev.product(this->weights).plus(this->bias);
    this->Activation_curr = this->activation.activation(this->Z_curr);
    return this->Activation_curr;
};

// layer backward propagation
// performex layer_backward_propagation on the weights and biases matrixed of 
// the layer 
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

// updates the weight and bias matrices with the calculated delta ,times the learningRate
void NeuralLayer::updateParameters(double &learningRate){
    Matrix newDelta = this->deltaWeights.timesConstant(-learningRate);
    Matrix newBias = this->deltaBias.timesConstant(-learningRate);

    this->weights = this->weights.plus(newDelta);
    this->bias = this->bias.plus(newBias);
}
