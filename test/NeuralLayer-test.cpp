#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/NeuralLayer.hpp"
#include "../include/Activation/Relu.hpp"
#include "../include/Activation/Sigmoid.hpp"

#include <memory>
#include <list>

TEST(NeuralLayer, layer_forward_propagation){

    std::vector<NeuralLayer> NeuralNetwork;

    NeuralLayer layer_1(2, 4, Relu());
    NeuralLayer layer_2(4, 4, Relu());
    NeuralLayer layer_3(4, 2, Relu());
    NeuralLayer layer_4(2, 1, Relu());

    NeuralNetwork.push_back(layer_1);
    NeuralNetwork.push_back(layer_2);
    NeuralNetwork.push_back(layer_3);
    NeuralNetwork.push_back(layer_4);

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

        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
        matrixData.show();
        layer.showWeights();

        // TODO : allocating object error

        matrixData = layer.layer_forward_propagation(layerInput);

        std::cout << "€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€"<< std::endl;
    }

    matrixData = Matrix(1,0);
}


/*TEST(NeuralLayer, layer_backward_propagation){*/

    ////TODO: test backwardlayer
/*}*/
