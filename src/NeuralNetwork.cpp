#include "NeuralNetwork.hpp"
#include "NeuralLayer.hpp"
#include "Activation/Relu.hpp"
#include "Activation/Sigmoid.hpp"
#include <algorithm>
#include <string>


NeuralNetwork::NeuralNetwork(int numOfLayers,int startNeurons, int hiddenNeurons, 
        int endNeurons, std::string activationStart, std::string activationEnd ){

    this->numOfLayers = numOfLayers;
    this->startNeurons = startNeurons;
    this->hiddenNeurons = hiddenNeurons;
    this->endNeurons = endNeurons;
    this->activationStart = activationStart;
    this->activationEnd = activationEnd;

}


void NeuralNetwork::init(){

    LayerVector.push_back(NeuralLayer(2, 4, Relu()));
    LayerVector.push_back(NeuralLayer(4, 4, Relu()));
    LayerVector.push_back(NeuralLayer(4, 4, Relu()));
    LayerVector.push_back(NeuralLayer(4, 1, Sigmoid()));

    //for (int i  = 0; i < numOfLayers ; i++) {
        //if(i == 0){
            //// TODO build up the NeuralNetwork 
            ////this->LayerVector.push_back(startNeurons,hiddenNeurons,activationStart);
        //}


    //}
}

std::vector<NeuralLayer> NeuralNetwork::getNeuralNetwork(){

    return this->LayerVector;
}
