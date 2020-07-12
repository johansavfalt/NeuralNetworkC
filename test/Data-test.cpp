#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "Data.hpp"
#include "Matrix.hpp"
#include <vector>


TEST(Data, getTrainingData){
    Matrix trainingDataSet(2, 2);
    Matrix testSetSet(4, 4);

    std::vector<Matrix> trainingData;
    std::vector<Matrix> testSet;

    trainingData.push_back(testSetSet);
    testSet.push_back(testSetSet);

    Data testdata(trainingData, testSet);

    //Data<Matrix> testdata = Data<Matrix>(trainingData, testSet);

    //EXPECT_EQ(testdata.getTestData(), testSet);
}

//TEST(Data, getTestData){
    //Matrix trainingDataSet(2, 2);
    //Matrix testSetSet(4, 4);

    //std::vector<Matrix> trainingData;
    //std::vector<Matrix> testSet;

    //trainingData.push_back(testSetSet);
    //testSet.push_back(testSetSet);

    //Data<Matrix> testdata = Data<Matrix>(trainingData, testSet);

    //EXPECT_EQ(testdata.getTestData(), testSet);

//}
