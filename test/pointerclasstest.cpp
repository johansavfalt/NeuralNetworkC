#include <iostream>
#include <memory>

class testclass{

    private:
        std::shared_ptr<Matrix> testMatrix;
        std::shared_ptr<Matrix> activation;

    public:
        std::shared_ptr<Matrix> test(std::shared_ptr<Matrix> matrix);
        std::shared_ptr<Matrix> test_unique(std::unique_ptr<Matrix> &);
        std::shared_ptr<Matrix> receiveUnique(std::unique_ptr<Matrix> &);

};


std::shared_ptr<Matrix> testclass::test_unique(std::unique_ptr<Matrix> &uniqueParameter){

    return this->receiveUnique(uniqueParameter);

    //return std::make_shared<Matrix>(1, 1);

};

std::shared_ptr<Matrix> testclass::receiveUnique(std::unique_ptr<Matrix> &uniqueParameter){
    uniqueParameter->show();
    return std::make_shared<Matrix>(2, 2);

};











std::shared_ptr<Matrix> testclass::test(std::shared_ptr<Matrix> matrix){
        //matrix->show();

        this->testMatrix = std::unique_ptr<Matrix>(new Matrix(1,1));
        this->activation = std::shared_ptr<Matrix>(new Matrix(1,1));

        this->testMatrix->setData(0, 0, 2.0);
        //this->testMatrix->show();

        activation->setData(0,0,this->testMatrix->getValue(0,0) * matrix->getValue(0,0));
        //activation->show();
        return activation;


        //std::cout << matrix->getValue(0, 0) << std::endl;

}







