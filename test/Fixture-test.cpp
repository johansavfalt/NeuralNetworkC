#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include<string>

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
     phraseClass * myPhrase1;
     phraseClass * myPhrase2;
     virtual void SetUp()
     {      
         myPhrase1 = new phraseClass("1234567890");
         myPhrase2 = new phraseClass("1234567890");  
     }

     virtual void TearDown()
     {
        delete myPhrase1;
        delete myPhrase2;  
     }
};

TEST_F(PhraseTest, OperatorTest)
{
    EXPECT_EQ(myPhrase1->getPhrase(), myPhrase2->getPhrase());
}
