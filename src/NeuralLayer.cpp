#include "../include/NeuralLayer.hpp"
#include "../include/Matrix.hpp"
#include "Activation/ActivationFunction.hpp"
#include <iostream>

NeuralLayer::NeuralLayer(unsigned int inputs, unsigned int units,
        const ActivationFunction &activation):

    activation(activation),
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

void NeuralLayer::showWeights(){
    this->weights.show();
};


Matrix NeuralLayer::layer_forward_propagation(Matrix &Activation_prev)
{
    this->Activation_prev = Activation_prev;
    this->Z_curr = this->Activation_prev.product(this->weights).plus(this->bias);
    this->Activation_curr = this->activation.activation(this->Z_curr);
    return this->Activation_curr;
};

/*Matrix NeuralLayer::layer_backward_propagation(Matrix &delta_Aprev)*/
//{
    //this->deltaWeights = this->Activation_prev.transpose().product(delta_Aprev);
    //double sum = 0.0;
    //for(int i = 0; i < delta_Aprev.getColumns(); i++){
        //sum += delta_Aprev.getValue(0, i);
    //}
    //this->deltaBias.fillwith(sum);
    //this->deltaCurr = delta_Aprev.product(this->weights.transpose());
    //this->deltaCurr1 = this->deltaCurr.hadamanproduct(
            //this->activation.activation_derivative(this->Activation_prev));
    //return this->deltaCurr1;

/*}*/;
