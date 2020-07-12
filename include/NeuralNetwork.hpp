#ifndef NeuralNetworkC_NeuralNetwork_H
#define NeuralNetworkC_NeuralNetwork_H

#include "NeuralLayer.hpp"
#include <string>

class NeuralNetwork
{
    private:
        int numOfLayers;
        int startNeurons;
        int hiddenNeurons;
        int endNeurons;

        std::string activationStart;
        std::string activationEnd;
        std::vector<NeuralLayer> LayerVector;

    public:
        NeuralNetwork(int,int,int,int, std::string, std::string);
        void init();
        std::vector<NeuralLayer> getNeuralNetwork();

};

#endif

