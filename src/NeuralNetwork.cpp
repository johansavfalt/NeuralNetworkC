#include "NeuralNetwork.hpp"
#include "NeuralLayer.hpp"
#include "Activation/Relu.hpp"
#include "Activation/Sigmoid.hpp"

#include <algorithm>
#include <functional>
#include <string>
#include <memory>
#include <iostream>


NeuralNetwork::NeuralNetwork(int numOfLayers,int startNeurons, int hiddenNeurons, 
        int endNeurons, std::string activationStart, std::string activationEnd ){

    this->numOfLayers = numOfLayers;
    this->startNeurons = startNeurons;
    this->hiddenNeurons = hiddenNeurons;
    this->endNeurons = endNeurons;
    this->activationStart = activationStart;
    this->activationEnd = activationEnd;

}

NeuralNetwork::NeuralNetwork(){};

NeuralNetwork::~NeuralNetwork(){
    this->LayerVector.clear();
}


void NeuralNetwork::init(){

    NeuralLayer *layer1 = new NeuralLayer(2, 4, Relu());
    NeuralLayer *layer2 = new NeuralLayer(4, 4, Relu());
    NeuralLayer *layer3 = new NeuralLayer(4, 4, Relu());
    NeuralLayer *layer4 = new NeuralLayer(4, 4, Relu());

    LayerVector.push_back(layer1);
    LayerVector.push_back(layer2);
    LayerVector.push_back(layer3);

    //for (int i  = 0; i < numOfLayers ; i++) {
        //if(i == 0){
            //// TODO build up the NeuralNetwork 
            ////this->LayerVector.push_back(startNeurons,hiddenNeurons,activationStart);
        //}


    //}
}

std::vector<NeuralLayer*> NeuralNetwork::getNeuralNetwork(){

    return this->LayerVector;
}
