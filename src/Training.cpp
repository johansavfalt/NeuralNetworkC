#include "Training.hpp"
#include "Matrix.hpp"
#include "NeuralLayer.hpp"
#include "Data.hpp"
#include <cstdio>
#include <math.h>
#include <list>
#include <iostream>
#include <vector>

Training::Training(NeuralNetwork NeuralLayers, double learningRate, int epochs,
                Data DataSet, int printResult){

    this->DataSet = DataSet;
    this->NeuralLayers = NeuralLayers;
    this->learningRate = learningRate;
    this->epochs = epochs;


}

void Training::train()
{

    for (int i = 0; i< this->epochs ; i++ ) {

        this->DataSet.shuffle();

        Matrix trainingData = this->DataSet.getTrainingData();
        Matrix testData = this->DataSet.getTestData();


        Matrix forwardpass = this->forwardPropagation(trainingData);
        Matrix deltaLoss = this->compute_cross_entropy_loss(forwardpass, testData , true);

        this->backwardPropagation(deltaLoss);
        this->updateParameters();

        //if(i % 1000 == 0){
            ////why is this showing wrong?
            //forwardpass.show();
            //testData.show();
            //std::cout << "///////////////////////" << std::endl;
        //}
    }
    
}

Matrix Training::forwardPropagation(Matrix data)
{
    for(auto * layer : this->NeuralLayers.getNeuralNetwork()){
        Matrix layerInput = data;
        data = layer->layer_forward_propagation(layerInput);
        data.show();

    } 
    return data;
};

Matrix Training::backwardPropagation(Matrix deltaLoss){

    std::vector<NeuralLayer *> nL = this->NeuralLayers.getNeuralNetwork();

    for(auto it = nL.rbegin(); it != nL.rend(); ++it){
        Matrix layerInput = deltaLoss;
        deltaLoss = (*it)->layer_backward_propagation(layerInput);
        
    };

    return deltaLoss;


}

void Training::updateParameters(){
    for(auto & layer: this->NeuralLayers.getNeuralNetwork())
        layer->updateParameters(this->learningRate);
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
