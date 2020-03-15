#include "gtest/gtest.h"
#include "Matrix.h"

TEST(MatrixTest, init){
    //arrange
    Matrix testMatrix(5, 5);
    //act
    testMatrix.init();
    //assert
    EXPECT_EQ(testMatrix.getData().size(), 5);
    EXPECT_EQ(testMatrix.getData()[0].size(), 5);
}

TEST(MatrixTest, setData){
    Matrix testMatrix(5, 5);
    //act
    testMatrix.init();
    testMatrix.setData(2, 4, 5.5);
    //assert
    EXPECT_EQ(testMatrix.getData()[2][4], 5.5);
    EXPECT_NE(testMatrix.getData()[0][0], 5.5);
}
