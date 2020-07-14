#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "Training.hpp"
#include "Matrix.hpp"
#include "Activation/Relu.hpp"
#include "Data.hpp"

#include <memory>
#include <iostream>
#include <vector>
#include <math.h>

TEST(Training, train){
    NeuralNetwork neuralNetwork;
    Data DataSet;

    double learningRate = 0.0001;
    int epochs = 100;
    int printResult = 0;

    Training training(neuralNetwork, learningRate, epochs, DataSet, printResult );
    training.train();

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
