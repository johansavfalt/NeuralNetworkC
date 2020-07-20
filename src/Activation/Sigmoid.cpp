#include "Activation/ActivationFunction.hpp"
#include "Activation/Sigmoid.hpp"
#include "Matrix.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

// Sigmoid class
// Creates activationfunction for Sigmoid 
// Example:
//  Matrix testMatrix(1,1);
//  this->activation.activation(testMatrix)

Matrix Sigmoid::activation(Matrix &Z_Matrix) const
{
   return applyforAllElements(Z_Matrix, Sigmoid::activate);
};

Matrix Sigmoid::activation_derivative(Matrix &Z_Matrix) const
{

    return applyforAllElements(Z_Matrix, Sigmoid::activate_derivative);


};

// applies the activationfunction (Sigmoid) for every element in the matrix
// takes the activationfunction (dervivative version or normal version ) as a parameter
//  Example :
//      Matrix testMatrix(1,1)
//      applyforAllElements(testMatrix, Relu::activation)
//
Matrix Sigmoid::applyforAllElements(Matrix &Z_Matrix, double (*activationtype)(double)) const
{
    int m = Z_Matrix.getRows();
    int n = Z_Matrix.getColumns();

    Matrix result = Matrix(m, n);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){

            result.setData(i,j, (*activationtype)(Z_Matrix.getValue(i,j)));
        }
    }

    return result;


};

// Sigmoid Activation
double Sigmoid::activate(double x)
{
    return 1 / (1 + exp(-x));
};

// Sigmoid Activation derivative
double Sigmoid::activate_derivative(double x)
{
    double sigVal = Sigmoid::activate(x);
    return sigVal * (1.0 - sigVal);
};
