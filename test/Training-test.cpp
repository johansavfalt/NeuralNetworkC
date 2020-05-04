#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../include/Training.hpp"
#include "../include/Matrix.hpp"

TEST(Training, cross_entropy_loss){
    Matrix predictDistribution(0, 0);
    Matrix trueDistribution(1, 1);
    Training::cross_entropy_loss(predictDistribution, trueDistribution);

}
