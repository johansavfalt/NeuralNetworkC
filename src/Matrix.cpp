#include "../include/Matrix.hpp"
#include <vector>
#include <iostream>
#include <memory>

Matrix::Matrix(){};

Matrix::Matrix(unsigned M, unsigned N)
{
    this->M = M;
    this->N = N;
    data.resize(M, std::vector<double>(N));
};

void Matrix::setData(unsigned m, unsigned n, double value)
{
    this->data[m][n] = value;
};

std::vector<std::vector<double> > Matrix::getData()
{
    return this->data;
};

int Matrix::getRows(){

    return this->M;
}
int Matrix::getColumns(){

    return this->N;
}

double Matrix::getValue(unsigned M,unsigned N)
{
    return this->data[M][N];
}


std::unique_ptr<Matrix> Matrix::random(unsigned M, unsigned N)
{
    auto A = std::make_unique<Matrix>(M, N);

    for(unsigned i = 0; i < M; i++){
        for(unsigned j = 0; j < N;j++){
            double f = (double)rand() / RAND_MAX;
            A->setData(i, j, f);
        }
    }
    return A;
};

Matrix Matrix::transpose()
{
    Matrix A(M, N);
    for(unsigned i = 0; i < M; i++){
        for(unsigned j = 0; j < N; j++){
            A.setData(j, i, this->getValue(i,j));
        }
    }
    return A;
};

void Matrix::fillwith(double value)
{
    for(unsigned i = 0; i < M; i++){
        for(unsigned j = 0; j < N; j++){
            this->setData(i, j, value);
        }
    }
};

std::shared_ptr<Matrix> Matrix::plus(std::shared_ptr<Matrix> B){
    if (B->getColumns() != this->getColumns() || B->getRows() != this->getRows()){
        B = this->getAdjustedMatrix(B, this->getRows());
    }
    auto C = std::make_unique<Matrix>(M, N);

    for(int i = 0;i < M;i++){
        for(int j = 0;j< N;j++){
            C->setData(i, j, this->getValue(i,j)+ B->getValue(i, j));
        }
    }
    return C;
};

std::shared_ptr<Matrix> Matrix::getAdjustedMatrix(std::shared_ptr<Matrix> B, const int n)
{
    auto C = std::make_shared<Matrix>(M, N);
    for(int i = 0; i < this->M; i++){
        for(int j = 0; j < n; j++){
            C->setData(i, j, B->getValue(0, j));
        }
    }
    return C;
}

Matrix Matrix::minus(Matrix &B){

    if (B.getColumns() != this->getColumns() ||  B.getRows() != this->getColumns() ){
        throw std::runtime_error("Illegal Matrix dimensions");
    }
    Matrix C(M, N);
    for(int i = 0;i < M;i++){
        for(int j = 0;j< N;j++){
            C.setData(i, j, this->data[i][j] - B.data[i][j]);
        }
    }
    return C;
};

Matrix Matrix::minusConstant(double constant)
{
    Matrix C(this->getRows(), this->getColumns());

    for(unsigned i = 0; i < M; i++){
        for(unsigned j = 0; j < N; j++){
            C.data[i][j] = this->data[i][j] - constant;
        }
    }
    return C;
};


std::shared_ptr<Matrix> Matrix::product(std::shared_ptr<Matrix> B) {
        if (this->N != B->M) throw std::runtime_error("Illegal matrix dimensions.");

        std::shared_ptr<Matrix> C = std::make_shared<Matrix>(this->M, B->N);

        for (int i = 0; i < this->M; i++){
            for (int j = 0; j < B->N; j++){
                for (int k = 0; k < this->N; k++){
                    C->data[i][j] += (this->data[i][k] * B->data[k][j]);
                }
            }
        }
        return C;
    }

Matrix Matrix::sum()
{
    double result = 0.0;
    Matrix C(1, 1);
    for(int i = 0;i< this->M;i++){
        for(int j = 0;j< this->N;j++){
            result += this->data[i][j];
        }
    }
    C.data[0][0] = result;
    return C;
}


Matrix Matrix::hadamanproduct(Matrix &B) {
        if (this->M != B.M & this->N != B.N) throw std::runtime_error("Illegal matrix dimensions");
        Matrix C(this->M, this->N);
        for (int i = 0; i < this->M; i++) {
            for (int j = 0; j < this->N; j++) {
                C.data[i][j] = this->data[i][j] * B.data[i][j];
            }
        }

        return C;
    }

Matrix Matrix::timesConstant(double constant) {
        Matrix C(this->M, this->N);
        for (int i = 0; i < this->M; i++) {
            for (int j = 0; j < this->N; j++) {
                C.data[i][j] = this->data[i][j] * constant;
            }
        }

        return C;
    }


void Matrix::show() {
        std::cout << "M: " + std::to_string(this->M) + " N:"+std::to_string(this->N) << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        for (int i = 0; i < this->M; i++) {
            for (int j = 0; j < this->N; j++){
                std::cout << std::to_string(this->data[i][j])+" ";
            }
            std::cout << " "+std::to_string(i) << std::endl;
        }
        for(int i = 0; i < this->M; i++){
            std::cout << std::to_string(i)+"        ";
        }
        std::cout << "" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
    }


