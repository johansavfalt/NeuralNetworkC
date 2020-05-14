#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/Training.hpp"
#include "../include/Matrix.hpp"
#include "pointerclasstest.cpp"

#include <memory>
#include <iostream>
#include <vector>

TEST(Training, cross_entropy_loss){
    Matrix predictDistribution(0, 0);
    Matrix trueDistribution(1, 1);
    Training::cross_entropy_loss(predictDistribution, trueDistribution);

}
TEST(pointertest, testingwithpointer){
    std::shared_ptr<Matrix> matrixData = std::make_shared<Matrix>(1, 1);
    matrixData->setData(0,0,1.0);

    std::shared_ptr<testclass> testPointer_1 = std::shared_ptr<testclass>(new testclass());

    std::shared_ptr<testclass> testPointer_2 = std::shared_ptr<testclass>(new testclass());

    std::shared_ptr<testclass> testPointer_3 = std::shared_ptr<testclass>(new testclass());


    std::vector<std::shared_ptr<testclass>> layers;

    layers.push_back(testPointer_1);
    layers.push_back(testPointer_2);
    layers.push_back(testPointer_3);


    for(auto layer: layers){
        std::shared_ptr<Matrix> layerInput = matrixData;
        matrixData = layer->test(layerInput);
        matrixData->show();

    }


}


