#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/Training.hpp"
#include "../include/Matrix.hpp"
#include "../include/Activation/Relu.hpp"
#include "pointerclasstest.cpp"

#include <memory>
#include <iostream>
#include <vector>

TEST(Training, cross_entropy_loss){
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

    Training::cross_entropy_loss(predictDistribution, trueDistribution);


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
