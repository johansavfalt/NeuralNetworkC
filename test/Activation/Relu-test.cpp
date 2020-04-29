#include "../../lib/googletest/googletest/include/gtest/gtest.h"
#include "../../include/Activation/Relu.hpp"
#include "../../include/Matrix.hpp"


TEST(ReluTest, activation){
    Matrix testMatrix_1(2, 2);
    testMatrix_1.fillwith(5.0);

    Matrix testMatrix_2(2, 2);
    testMatrix_2.fillwith(-5.0);

    Relu reluTest; 

    EXPECT_EQ(reluTest.activation(testMatrix_1).getValue(1, 1), 5.0);
    EXPECT_EQ(reluTest.activation(testMatrix_2).getValue(0, 0), 0.0);

}

TEST(ReluTest, activation_derivative){
    Matrix testMatrix_1(2, 2);
    testMatrix_1.fillwith(5.0);

    Matrix testMatrix_2(2, 2);
    testMatrix_2.fillwith(-5.0);

    Relu reluTest; 

    EXPECT_EQ(reluTest.activation_derivative(testMatrix_1).getValue(1, 1), 1.0);
    EXPECT_EQ(reluTest.activation_derivative(testMatrix_2).getValue(0, 0), 0.0);

}
