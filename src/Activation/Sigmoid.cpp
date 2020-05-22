#include "../../include/Activation/ActivationFunction.hpp"
#include "../../include/Activation/Sigmoid.hpp"
#include "../../include/Matrix.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


Matrix Sigmoid::activation(Matrix &Z_Matrix)
{
   return applyforAllElements(Z_Matrix, Sigmoid::activate);
};

Matrix Sigmoid::activation_derivative(Matrix &Z_Matrix)
{

    return applyforAllElements(Z_Matrix, Sigmoid::activate_derivative);


};

Matrix Sigmoid::applyforAllElements(Matrix &Z_Matrix, double (*activationtype)(double))
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

double Sigmoid::activate(double x)
{
    return 1 / (1 + exp(-x));
};

double Sigmoid::activate_derivative(double x)
{
    double sigVal = Sigmoid::activate(x);
    return sigVal * (1.0 - sigVal);
};
