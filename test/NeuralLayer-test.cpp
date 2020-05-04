#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/NeuralLayer.hpp"
#include "../include/Activation/Relu.hpp"
#include "../include/Activation/Sigmoid.hpp"

#include <memory>
#include <list>

TEST(NeuralLayer, layer_forward_propagation){

    std::unique_ptr<NeuralLayer> NeuralLayer_1(new NeuralLayer(2, 4, Relu()));
    std::unique_ptr<NeuralLayer> NeuralLayer_2(new NeuralLayer(4, 4, Relu()));
    std::unique_ptr<NeuralLayer> NeuralLayer_3(new NeuralLayer(4, 2, Relu()));
    std::unique_ptr<NeuralLayer> NeuralLayer_4(new NeuralLayer(2, 1, Sigmoid()));

    /*std::list<std::unique_ptr<NeuralLayer>> NeuralNetwork;*/

    // TODO : add pointers to list, maby not add the shared pointers directly? but an * instead
    //NeuralNetwork.push_front(NeuralLayer_1);
    //NeuralNetwork.push_front(NeuralLayer_2);
    //NeuralNetwork.push_front(NeuralLayer_3);
    //NeuralNetwork.push_front(NeuralLayer_4);


    Relu relu;
    NeuralLayer neuralLayer(2, 2, relu);
    Matrix matrix = Matrix::random(2, 2);

    neuralLayer.layer_forward_propagation(matrix);
}


TEST(NeuralLayer, layer_backward_propagation){

    //TODO: test backwardlayer
}
