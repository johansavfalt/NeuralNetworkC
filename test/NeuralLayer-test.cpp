#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/NeuralLayer.hpp"
#include "../include/Activation/Relu.hpp"
#include "../include/Activation/Sigmoid.hpp"

#include <memory>
#include <list>

TEST(NeuralLayer, layer_forward_propagation){

    std::list<std::unique_ptr<NeuralLayer>> NeuralNetwork;

    NeuralNetwork.push_back(std::make_unique<NeuralLayer>(2, 4, Relu()));
    NeuralNetwork.push_back(std::make_unique<NeuralLayer>(4, 4, Relu()));
    NeuralNetwork.push_back(std::make_unique<NeuralLayer>(4, 2, Relu()));
    NeuralNetwork.push_back(std::make_unique<NeuralLayer>(2, 1, Relu()));

    auto matrixData = std::make_shared<Matrix>(4, 2);
    matrixData->setData(0, 0, 1.0);
    matrixData->setData(0, 1, 0.0);

    matrixData->setData(1, 0, 0.0);
    matrixData->setData(1, 1, 1.0);

    matrixData->setData(2, 0, 1.0);
    matrixData->setData(2, 1, 1.0);

    matrixData->setData(3, 0, 0.0);
    matrixData->setData(3, 1, 0.0);

    for(auto const& layer : NeuralNetwork){
        auto layerInput = std::make_shared<Matrix>(*matrixData);
        matrixData = std::make_shared<Matrix>(layer->layer_forward_propagation(*layerInput));
        matrixData->show();
    }
}


TEST(NeuralLayer, layer_backward_propagation){

    //TODO: test backwardlayer
}
