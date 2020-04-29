#include "../../lib/googletest/googletest/include/gtest/gtest.h"
#include "../../include/Activation/Sigmoid.hpp"
#include "../../include/Matrix.hpp"


TEST(SigmoidTest, activation){
    Matrix testMatrix_1(2, 2);
    testMatrix_1.fillwith(5.0);

    Matrix testMatrix_2(2, 2);
    testMatrix_2.fillwith(-5.0);

    Sigmoid sigmoidTest; 

    EXPECT_NEAR(sigmoidTest.activation(testMatrix_1).getValue(1, 1), 0.993307, 0.0001);
    EXPECT_NEAR(sigmoidTest.activation(testMatrix_2).getValue(0, 0), 0.00669285, 0.0001);

}

TEST(SigmoidTest, activation_derivative){
    Matrix testMatrix_1(2, 2);
    testMatrix_1.fillwith(5.0);

    Matrix testMatrix_2(2, 2);
    testMatrix_2.fillwith(-5.0);

    Sigmoid sigmoidTest; 

    EXPECT_NEAR(sigmoidTest.activation_derivative(testMatrix_1).getValue(1, 1), 0.0066452439, 0.001);  
    EXPECT_NEAR(sigmoidTest.activation_derivative(testMatrix_2).getValue(0, 0), 0.0066452439, 0.001);  


}
