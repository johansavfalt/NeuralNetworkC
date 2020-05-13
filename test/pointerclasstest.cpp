#include <iostream>
#include <memory>

class testclass{

    private:
        std::shared_ptr<Matrix> testMatrix;
        std::shared_ptr<Matrix> activation;

    public:
        std::shared_ptr<Matrix> test(std::shared_ptr<Matrix> matrix);


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

