#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "Training.hpp"
#include "Matrix.hpp"
#include "Activation/Relu.hpp"
#include "Activation/Sigmoid.hpp"
#include "Data.hpp"

#include <cstdio>
#include <memory>
#include <iostream>
#include <vector>
#include <math.h>

TEST(Training, train){
    Matrix testSetSet(4, 1);
    Matrix trainingData(4, 2);

    trainingData.setData(0, 0, 1.0);
    trainingData.setData(0, 1, 0.0);

    trainingData.setData(1, 0, 0.0);
    trainingData.setData(1, 1, 1.0);

    trainingData.setData(2, 0, 1.0);
    trainingData.setData(2, 1, 1.0);

    trainingData.setData(3, 0, 0.0);
    trainingData.setData(3, 1, 0.0);

    testSetSet.setData(0, 0, 1.0);
    testSetSet.setData(1, 0, 1.0);
    testSetSet.setData(2, 0, 0.0);
    testSetSet.setData(3, 0, 0.0);

    Data DataSet(trainingData, testSetSet);
 
    std::vector<NeuralLayer> neuralNetwork;

    neuralNetwork.push_back(NeuralLayer(2, 4, Relu()));
    neuralNetwork.push_back(NeuralLayer(4, 4, Relu()));
    neuralNetwork.push_back(NeuralLayer(4, 4, Relu()));
    neuralNetwork.push_back(NeuralLayer(4, 1, Sigmoid()));

    double learningRate = 0.01;
    int epochs = 50;
    int printResult = 0;

    Training training(learningRate, epochs, DataSet, printResult);
    training.train(neuralNetwork);

}


TEST(Training, cross_entropy_loss){
    Matrix predictDistribution(4, 1);
    Matrix trueDistribution(1, 4);

    predictDistribution.setData(0, 0, 0.4333);
    predictDistribution.setData(1, 0, 0.3231);
    predictDistribution.setData(2, 0, 0.3321);
    predictDistribution.setData(3, 0, 0.1131);

    trueDistribution.setData(0, 0, 0.0);
    trueDistribution.setData(0, 1, 1.0);
    trueDistribution.setData(0, 2, 0.0);
    trueDistribution.setData(0, 3, 1.0);


    EXPECT_NEAR(Training::cross_entropy_loss(predictDistribution, trueDistribution).getValue(0, 0), 1.0702, 0.5);

}

TEST(Training, cross_entropy_loss_derivative){
    Matrix predictDistribution(4, 1);
    Matrix trueDistribution(1, 4);

    predictDistribution.setData(0, 0, 14.332);
    predictDistribution.setData(1, 0, 13.323);
    predictDistribution.setData(2, 0, 88.332);
    predictDistribution.setData(3, 0, 12.113);

    trueDistribution.setData(0, 0, 0.0);
    trueDistribution.setData(0, 1, 1.0);
    trueDistribution.setData(0, 2, 0.0);
    trueDistribution.setData(0, 3, 1.0);

    Matrix result = 
        Training::compute_cross_entropy_loss(predictDistribution, trueDistribution, true);

    ASSERT_EQ(result.getValue(0,0), 14.332);
    ASSERT_EQ(result.getValue(1,0), 12.323);
    ASSERT_EQ(result.getValue(2,0), 88.332);
    ASSERT_EQ(result.getValue(3,0), 11.113);


}
