#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/NeuralLayer.hpp"
#include "../include/Activation/Relu.hpp"
#include "../include/Activation/Sigmoid.hpp"

#include <memory>
#include <list>

TEST(NeuralLayer, layer_forward_propagation){

    std::vector<NeuralLayer> NeuralNetwork;

    NeuralNetwork.push_back(NeuralLayer(2, 4, Relu()));
    NeuralNetwork.push_back(NeuralLayer(4, 4, Relu()));
    NeuralNetwork.push_back(NeuralLayer(4, 4, Relu()));
    NeuralNetwork.push_back(NeuralLayer(4, 1, Sigmoid()));

    Matrix matrixData = Matrix(4, 2);

    matrixData.setData(0, 0, 1.0);
    matrixData.setData(0, 1, 0.0);

    matrixData.setData(1, 0, 0.0);
    matrixData.setData(1, 1, 1.0);

    matrixData.setData(2, 0, 1.0);
    matrixData.setData(2, 1, 1.0);

    matrixData.setData(3, 0, 0.0);
    matrixData.setData(3, 1, 0.0);


    for(auto layer : NeuralNetwork){

        auto layerInput = matrixData;
        matrixData = layer.layer_forward_propagation(layerInput);
    }

}


/*TEST(NeuralLayer, layer_backward_propagation){*/

    ////TODO: test backwardlayer
/*}*/
