#include "gtest/gtest.h"
#include "Matrix.h"

TEST(MatrixTest, Matrix){
    //arrange
    Matrix testMatrix(5, 5);
    //assert
    EXPECT_EQ(testMatrix.getData().size(), 5);
    EXPECT_EQ(testMatrix.getData()[0].size(), 5);
}

TEST(MatrixTest, setData){
    Matrix testMatrix(5, 5);
    //act
    testMatrix.setData(2, 4, 5.5);
    //assert
    EXPECT_EQ(testMatrix.getData()[2][4], 5.5);
    EXPECT_NE(testMatrix.getData()[0][0], 5.5);
}

TEST(MatrixTest,getRows){
    Matrix testMatrix(5, 5);
    EXPECT_EQ(testMatrix.getRows(), 5);
}

TEST(MatrixTest,getColumns){
    Matrix testMatrix(5, 5);
    EXPECT_EQ(testMatrix.getColumns(), 5);
}

TEST(MatrixTest,getValue){
    Matrix testMatrix(5, 5);
    testMatrix.setData(2, 2 , 2.0);
    EXPECT_EQ(testMatrix.getValue(2, 2), 2.0);
}

TEST(MatrixTest, transpose){
    //--arrage
    Matrix testMatrix(5, 5);
    testMatrix.setData(1, 2 , 1.0);
    testMatrix.setData(3, 4 , 2.0);
    //---assert
    Matrix trans = testMatrix.transpose();
    //---act
    EXPECT_EQ(trans.getValue(2, 1), 1.0);
    EXPECT_EQ(trans.getValue(4, 3), 2.0);
}
TEST(MatrixTest, fillwith){

    Matrix testMatrix(2, 2);

    testMatrix.fillwith(1.0);

    for(unsigned i = 0; i < 2; i++){
        for(unsigned j = 0; j < 2; j++){
            EXPECT_EQ(testMatrix.getData()[i][j], 1.0);
        }
    }
}
TEST(MatrixTest, plus){
    Matrix testMatrix_1(2, 2);
    Matrix testMatrix_2(2, 2);

    testMatrix_1.fillwith(1.0);
    testMatrix_2.fillwith(1.0);

    Matrix plusResult = testMatrix_1.plus(testMatrix_2);

    for(unsigned i = 0; i < 2; i++){
        for(unsigned j = 0; j < 2; j++){
            EXPECT_EQ(plusResult.getData()[i][j], 2.0);
        }
    }
}

TEST(MatrixTest, minus){
    Matrix testMatrix_1(2, 2);
    Matrix testMatrix_2(2, 2);

    testMatrix_1.fillwith(1.0);
    testMatrix_2.fillwith(1.0);

    Matrix minusResult = testMatrix_1.minus(testMatrix_2);

    for(unsigned i = 0; i < 2; i++){
        for(unsigned j = 0; j < 2; j++){
            EXPECT_EQ(minusResult.getData()[i][j], 0.0);
        }
    }
}

TEST(MatrixTest, minusConstant){
    Matrix testMatrix_1(2, 2);
    testMatrix_1.fillwith(1.0);
    Matrix minusConstantResult = testMatrix_1.minusConstant(1.0);

    for(unsigned i = 0; i < 2; i++){
        for(unsigned j = 0; j < 2; j++){
            EXPECT_EQ(minusConstantResult.getData()[i][j], 0.0);
        }
    }
}
TEST(MatrixTest, product){
    Matrix testMatrix_1(2, 2);
    Matrix testMatrix_2(2, 2);

    testMatrix_1.fillwith(5.0);
    testMatrix_2.fillwith(5.0);
    Matrix productTest = testMatrix_1.product(testMatrix_2);

    for(unsigned i = 0; i < 2; i++){
        for(unsigned j = 0; j < 2; j++){
            EXPECT_EQ(productTest.getValue(i, j), 50.0);
        }
    }
}
TEST(MatrixTest, sum){

    Matrix testMatrix(2, 2);
    testMatrix.fillwith(1.0);
    Matrix sum = testMatrix.sum();
    EXPECT_EQ(sum.getValue(0, 0), 4);
}
// TODO : add more test
