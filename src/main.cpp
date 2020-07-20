#include <iostream>
#include "Matrix.hpp"
#include "Data.hpp"
#include "NeuralLayer.hpp"
#include "Activation/Relu.hpp"
#include "Activation/Sigmoid.hpp"
#include "Training.hpp"

Matrix getTestSet(){
    Matrix testSet(4, 1);

    testSet.setData(0, 0, 1.0);
    testSet.setData(1, 0, 1.0);
    testSet.setData(2, 0, 0.0);
    testSet.setData(3, 0, 0.0);

    return testSet;

};

Matrix getTrainingData(){
    Matrix trainingData(4, 2);

    trainingData.setData(0, 0, 1.0);
    trainingData.setData(0, 1, 0.0);

    trainingData.setData(1, 0, 0.0);
    trainingData.setData(1, 1, 1.0);

    trainingData.setData(2, 0, 1.0);
    trainingData.setData(2, 1, 1.0);

    trainingData.setData(3, 0, 0.0);
    trainingData.setData(3, 1, 0.0);
    return trainingData;

};

int main() {

    // create trainingdata
    Data DataSet(getTrainingData(), getTestSet());
 
    /// Create NeuralNetwork (vector of the NeuralLayer class)
    std::vector<NeuralLayer> neuralNetwork;
    neuralNetwork.push_back(NeuralLayer(2, 4, Relu()));
    neuralNetwork.push_back(NeuralLayer(4, 4, Relu()));
    neuralNetwork.push_back(NeuralLayer(4, 4, Relu()));
    neuralNetwork.push_back(NeuralLayer(4, 1, Sigmoid()));
    /// --- end NeuralNetwork creation

    /// Set HyperParametes
    double learningRate = 0.01;
    int epochs = 50;
    int printResult = 0;
    /// --- end HyperParameters

    // set Trainingclass
    Training training(learningRate, epochs, DataSet, printResult);
    // train network
    training.train(neuralNetwork);

    return 0;
}
