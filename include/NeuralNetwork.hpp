#ifndef NeuralNetworkC_NeuralNetwork_H
#define NeuralNetworkC_NeuralNetwork_H

#include "NeuralLayer.hpp"
#include <functional>
#include <string>
#include <memory>
#include <list>

class NeuralNetwork
{
    private:
        int numOfLayers;
        int startNeurons;
        int hiddenNeurons;
        int endNeurons;

        std::string activationStart;
        std::string activationEnd;
        //std::vector<std::unique_ptr<NeuralLayer>> LayerVector;
        std::vector<NeuralLayer*> LayerVector;

    public:
        NeuralNetwork(int,int,int,int, std::string, std::string);
        NeuralNetwork();
        ~NeuralNetwork();
        void init();
        //std::vector<std::unique_ptr<NeuralLayer>> getNeuralNetwork();
        std::vector<NeuralLayer*> getNeuralNetwork();

};

#endif

