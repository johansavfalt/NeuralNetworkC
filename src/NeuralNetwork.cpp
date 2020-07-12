#include "NeuralNetwork.hpp"
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
    for (int i  = 0; i < numOfLayers ; i++) {
        if(i == 0){
            // TODO build up the NeuralNetwork 
            //this->LayerVector.push_back(startNeurons,hiddenNeurons,activationStart);
        }


    }
}
