#include "../include/Matrix.hpp"
#include <vector>
#include <iostream>

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


Matrix Matrix::random(unsigned M, unsigned N)
{
    Matrix A(M, N);
    for(unsigned i = 0; i < M; i++){
        for(unsigned j = 0; j < N;j++){
            double f = (double)rand() / RAND_MAX;
            A.setData(i, j, f);
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

Matrix Matrix::plus(Matrix &B){
    if (B.getColumns() != this->getColumns() ||  B.getRows() != this->getColumns() ){
        throw std::runtime_error("Illegal Matrix dimensions");
    }
    Matrix C(M, N);
    for(int i = 0;i < M;i++){
        for(int j = 0;j< N;j++){
            C.setData(i, j, this->data[i][j] + B.data[i][j]);
        }
    }
    return C;
};

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


Matrix Matrix::product(Matrix &B) {
        if (this->N != B.M) throw std::runtime_error("Illegal matrix dimensions.");

        Matrix C(this->M, B.N);

        for (int i = 0; i < this->M; i++){
            for (int j = 0; j < B.N; j++){
                for (int k = 0; k < this->N; k++){
                    C.data[i][j] += (this->data[i][k] * B.data[k][j]);
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


