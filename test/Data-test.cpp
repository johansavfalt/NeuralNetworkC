#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "Data.hpp"
#include "Matrix.hpp"
#include <vector>
#include <iostream>


TEST(Data, getTrainingData){
    Matrix trainingDataSet(2, 2);
    Matrix testSetSet(4, 4);

    std::vector<Matrix> trainingData;
    std::vector<Matrix> testSet;

    trainingData.push_back(testSetSet);
    testSet.push_back(testSetSet);

    Data testdata(trainingData, testSet);

    EXPECT_EQ(testdata.getTrainingData().at(0).getData(), trainingData.at(0).getData());
}

TEST(Data, getTestData){
    Matrix trainingDataSet(2, 2);
    Matrix testSetSet(4, 4);

    std::vector<Matrix> trainingData;
    std::vector<Matrix> testSet;

    trainingData.push_back(testSetSet);
    testSet.push_back(testSetSet);

    Data testdata(trainingData, testSet);

    EXPECT_EQ(testdata.getTestData().at(0).getData(), testSet.at(0).getData());
}
