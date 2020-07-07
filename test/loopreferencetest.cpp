#include "../include/Matrix.hpp"
#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include <list>

class LoopReferenceTest {
    public:
        Matrix testMatrix;
        //Matrix &testMatrix;

        LoopReferenceTest(){};
        //LoopReferenceTest(Matrix &testMatrix):testMatrix(testMatrix){};

        Matrix setTestMatrix(Matrix &testRef){
            //testRef.show();
            this->testMatrix = testRef;
            this->testMatrix.setData(1, 1, 100*this->testMatrix.getValue(1, 1));
            return this->testMatrix;
        }

        void printTestMatrix(){
            this->testMatrix.show();
        };

};

TEST(loopreferencetest, testingtesting){
    std::vector<LoopReferenceTest> testVector;

    testVector.push_back(LoopReferenceTest());
    testVector.push_back(LoopReferenceTest());
    testVector.push_back(LoopReferenceTest());

    Matrix loopMatrix(5, 5);
    loopMatrix.fillwith(25.0);

    Matrix loopMatrix_1(5, 5);
    loopMatrix_1.fillwith(25.0);

    Matrix loopMatrix_2(5, 5);
    loopMatrix_2.fillwith(25.0);

    //i want to do this in a loop
    Matrix A = testVector.at(0).setTestMatrix(loopMatrix);
    Matrix B = testVector.at(1).setTestMatrix(A);
    Matrix C = testVector.at(2).setTestMatrix(B);

    loopMatrix.show();
    A.show();
    B.show();
    C.show();


    //this works , but not in the loop!?!?
    //testVector.at(0).setTestMatrix(loopMatrix_1);
    //testVector.at(1).setTestMatrix(loopMatrix_2);

    for(auto loopRef : testVector){
        //loopRef.setTestMatrix(loopMatrix_1);
        //loopRef.printTestMatrix();

    }
    //this is empty?
    //testVector.at(0).printTestMatrix();
    //testVector.at(1).printTestMatrix();

};
