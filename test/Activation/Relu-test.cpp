#include "../../lib/googletest/googletest/include/gtest/gtest.h"
#include "../../include/Activation/Relu.hpp"
#include "../../include/Matrix.h"


TEST(ReluTest, activation){
    Matrix testMatrix(2, 2);
    testMatrix.fillwith(5.0);

    // TODO: need to add default constructor to Relu, 
    //Relu reluTest();
    //std::cout << "Johan" << std::endl;
    // TODO: need to test the output here 
    //std::cout << reluTest.activation(testMatrix).getValue(1,1) << std::endl;
    //EXPECT_EQ(reluTest.activation(testMatrix).getValue(2, 2), 5);

}

/*TEST(MatrixTest, Matrix){*/
    ////arrange
    //Matrix testMatrix(5, 5);
    ////assert
    //EXPECT_EQ(testMatrix.getData().size(), 5);
    //EXPECT_EQ(testMatrix.getData()[0].size(), 5);
/*}*/

