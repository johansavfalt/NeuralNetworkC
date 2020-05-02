#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/NeuralLayer.hpp"
#include "../include/Activation/Relu.hpp"

TEST(NeuralLayer, layer_forward_propagation){

    Relu relu;
    NeuralLayer neuralLayer(2, 2, relu);
    Matrix matrix = Matrix::random(2, 2);
    neuralLayer.layer_forward_propagation(matrix);
}
TEST(NeuralLayer, layer_backward_propagation){

    //TODO: test backwardlayer
}
