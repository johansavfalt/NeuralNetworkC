#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "Data.hpp"
#include "Matrix.hpp"
#include <vector>
#include <iostream>

TEST(Data, shuffle){
    Matrix testSetSet(4, 1);
    Matrix trainingData(4, 2);

    trainingData.setData(0, 0, 1.0);
    trainingData.setData(0, 1, 0.0);

    trainingData.setData(1, 0, 0.0);
    trainingData.setData(1, 1, 1.0);

    trainingData.setData(2, 0, 1.0);
    trainingData.setData(2, 1, 1.0);

    trainingData.setData(3, 0, 0.0);
    trainingData.setData(3, 1, 0.0);

    testSetSet.setData(0, 0, 1.0);
    testSetSet.setData(1, 0, 1.0);
    testSetSet.setData(2, 0, 0.0);
    testSetSet.setData(3, 0, 0.0);

    Data DataSet(trainingData, testSetSet);
    DataSet.shuffle();

}

