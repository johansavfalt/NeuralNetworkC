#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "Data.hpp"
#include "Matrix.hpp"
#include <vector>
#include <iostream>

TEST(Data, init){
    Matrix testSetSet(4, 2);
    Matrix trainingData(4, 1);

    trainingData.setData(0, 0, 1.0);
    trainingData.setData(0, 1, 0.0);

    trainingData.setData(1, 0, 0.0);
    trainingData.setData(1, 1, 1.0);

    trainingData.setData(2, 0, 1.0);
    trainingData.setData(2, 1, 1.0);

    trainingData.setData(3, 0, 0.0);
    trainingData.setData(3, 1, 0.0);

    testSetSet.setData(0, 0, 1.0);
    testSetSet.setData(0, 1, 1.0);
    testSetSet.setData(0, 2, 0.0);
    testSetSet.setData(0, 3, 0.0);

    Data DataSet(trainingData, testSetSet);
    DataSet.init();

}

//TEST(Data, getTrainingData){
    //Matrix trainingDataSet(2, 2);
    //Matrix testSetSet(4, 4);

    //Matrix trainingData(4, 2);

    //trainingData.setData(0, 0, 1.0);
    //trainingData.setData(0, 1, 0.0);

    //trainingData.setData(1, 0, 0.0);
    //trainingData.setData(1, 1, 1.0);

    //trainingData.setData(2, 0, 1.0);
    //trainingData.setData(2, 1, 1.0);

    //trainingData.setData(3, 0, 0.0);
    //trainingData.setData(3, 1, 0.0);


    //trainingData.push_back(testSetSet);
    //testSet.push_back(testSetSet);

    //Data testdata(trainingData, testSet);

    //testdata.shuffle();

    //TODO should test it return a valid matrix
    //EXPECT_EQ(typeid(Matrix), typeid(std::result_of<testdata.getTrainingData() >::type));
//}

//TEST(Data, getTestData){
    //Matrix trainingDataSet(2, 2);
    //Matrix testSetSet(4, 4);

    //std::vector<Matrix> trainingData;
    //std::vector<Matrix> testSet;

    //trainingData.push_back(testSetSet);
    //testSet.push_back(testSetSet);

    //Data testdata(trainingData, testSet);

    ////EXPECT_EQ(testdata.getTestData().at(0).getData(), testSet.at(0).getData());
//}
