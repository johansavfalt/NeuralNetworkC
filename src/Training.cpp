#include "Training.hpp"
#include "Matrix.hpp"
#include "NeuralLayer.hpp"
#include "Data.hpp"
#include <cstdio>
#include <math.h>
#include <list>
#include <iostream>
#include <vector>

Training::Training(double learningRate, int epochs,
                Data DataSet, int printResult){

    this->DataSet = DataSet;
    this->learningRate = learningRate;
    this->epochs = epochs;


}

void Training::train(std::vector<NeuralLayer> & neuralNetwork)
{

    for (int i = 0; i< this->epochs ; i++ ) {

        this->DataSet.shuffle();

        Matrix trainingData = this->DataSet.getTrainingData();
        Matrix testData = this->DataSet.getTestData();


        Matrix forwardpass = this->forwardPropagation(neuralNetwork, trainingData);
        Matrix deltaLoss = this->compute_cross_entropy_loss(forwardpass, testData , true);

        this->backwardPropagation(neuralNetwork, deltaLoss);
        this->updateParameters(neuralNetwork);

        if(i % 5 == 0){
            deltaLoss.show(); // TODO it seams to work!!!!
            std::cout << "///////////////////////" << std::endl;
        }
    }
    
}

Matrix Training::forwardPropagation(std::vector<NeuralLayer> & NeuralNetwork, Matrix data)
{
    for(auto & layer : NeuralNetwork){
        Matrix layerInput = data;
        data = layer.layer_forward_propagation(layerInput);

    } 
    return data;
};

Matrix Training::backwardPropagation(std::vector<NeuralLayer> & nL, Matrix deltaLoss){

    for(auto it = nL.rbegin(); it != nL.rend(); ++it){
        Matrix layerInput = deltaLoss;
        deltaLoss = it->layer_backward_propagation(layerInput);
        
    };

    return deltaLoss;


}

void Training::updateParameters(std::vector<NeuralLayer> & neuralNetwork){
    for(auto & layer: neuralNetwork)
        layer.updateParameters(this->learningRate);
}

Matrix Training::compute_cross_entropy_loss(Matrix &data, Matrix &test, bool derivative)
{
    if(derivative){
        return data.minus(test);
    } else{
        return cross_entropy_loss(data, test);
    }

}

Matrix Training::cross_entropy_loss(Matrix &predictDistribution, Matrix &trueDistribution){

    double endError;
    int M = predictDistribution.getRows();

    std::vector<double> batchResult;


    for(int i = 0; i < M; i++){

        double error;
        double singleTrue = trueDistribution.getValue(0, i);
        double singlePred = predictDistribution.getValue(i, 0);


        if(singleTrue == 1){
            error = log(singlePred) * -1.0;
        } else{
            error = log(1.0 - singlePred) * -1.0;
        }
        
        batchResult.push_back(error);
    }


    for(auto x : batchResult){
        endError += x;
    }


    double doubleValue = (1.0/M * endError);
    Matrix result(1, 1);
    result.fillwith(doubleValue);
    return result;
}
