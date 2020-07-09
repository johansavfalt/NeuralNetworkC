#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "Matrix.hpp"
#include "NeuralLayer.hpp"
#include "Activation/Relu.hpp"
#include "Activation/Sigmoid.hpp"
#include <string>
#include <vector>

class phraseClass {
    public:
        std::string phrase;
        
        phraseClass(std::string phrase){
            this->phrase = phrase;

        };

        std::string getPhrase(){
            return this->phrase;

        }


};

class PhraseTest : public ::testing::Test
{
protected:

     std::vector<NeuralLayer> * NeuralNetwork;
     Matrix * matrixData;

     phraseClass * myPhrase1;
     phraseClass * myPhrase2;

     virtual void SetUp()
     {      
         NeuralNetwork = new std::vector<NeuralLayer>;
         matrixData = new Matrix(4, 2);

         NeuralNetwork->push_back(NeuralLayer(2, 4, Relu()));
         NeuralNetwork->push_back(NeuralLayer(4, 4, Relu()));
         NeuralNetwork->push_back(NeuralLayer(4, 4, Relu()));
         NeuralNetwork->push_back(NeuralLayer(4, 1, Sigmoid()));

         matrixData->setData(0, 0, 1.0);
         matrixData->setData(0, 1, 0.0);

         matrixData->setData(1, 0, 0.0);
         matrixData->setData(1, 1, 1.0);

         matrixData->setData(2, 0, 1.0);
         matrixData->setData(2, 1, 1.0);

         matrixData->setData(3, 0, 0.0);
         matrixData->setData(3, 1, 0.0);

         myPhrase1 = new phraseClass("1234567890");
         myPhrase2 = new phraseClass("1234567890");  
     }

     virtual void TearDown()
     {
        delete NeuralNetwork;
        delete matrixData;

        delete myPhrase1;
        delete myPhrase2;  
     }
};

TEST_F(PhraseTest, OperatorTest)
{
    //for(auto layer: *NeuralNetwork){
        //Matrix layerInput = *matrixData;
        ////layer.showWeights();
        ////layerInput.show();
        //layer.layer_forward_propagation(layerInput);
        ///[>matrixData = layer.layer_forward_propagation(layerInput);
        ////layer.showWeights();


    //}
    //EXPECT_EQ(myPhrase1->getPhrase(), myPhrase2->getPhrase());
}
