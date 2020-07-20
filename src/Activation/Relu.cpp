#include "Activation/ActivationFunction.hpp"
#include "Activation/Relu.hpp"
#include "Matrix.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

// Relu class
// Creates activationfunction for relu
// Example:
//  Matrix testMatrix(1,1);
//  this->activation.activation(testMatrix)

Matrix Relu::activation(Matrix &Z_Matrix) const
{
   return applyforAllElements(Z_Matrix, Relu::activate);
}

Matrix Relu::activation_derivative(Matrix &Z_Matrix) const
{

    return applyforAllElements(Z_Matrix, Relu::activate_derivative);


};

// applies the activationfunction (Relu) for every element in the matrix
// takes the activationfunction (dervivative version or normal version ) as a parameter
//  Example :
//      Matrix testMatrix(1,1)
//      applyforAllElements(testMatrix, Relu::activate)
//
Matrix Relu::applyforAllElements(Matrix &Z_Matrix,double (*activationtype)(double)) const
{

    int m = Z_Matrix.getRows();
    int n = Z_Matrix.getColumns();

    Matrix result(m, n); 

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){

            result.setData(i,j, (*activationtype)(Z_Matrix.getValue(i,j)));
        }
    }

    return result;


};

// Relu Activation function
double Relu::activate(double x)
{
    return std::max(x, 0.0);
}

// Relu activation derivative
double Relu::activate_derivative(double x)
{
    if(x > 0.0){
        return 1.0;
    } else{
        return 0.0;
    }
}
