#include "../../include/Activation/ActivationFunction.hpp"
#include "../../include/Activation/Relu.hpp"
#include "../../include/Matrix.h"

#include <vector>
#include <algorithm>


Matrix Relu::activation(Matrix &Z_Matrix) 
{
   return applyforAllElements(Z_Matrix, Relu::activate);


}

Matrix Relu::activation_derivative(Matrix &Z_Matrix) 
{

    return applyforAllElements(Z_Matrix, Relu::activate_derivative);


};

Matrix Relu::applyforAllElements(Matrix &Z_Matrix, double (*activationtype)(double)) 
{
    int m = Z_Matrix.getRows();
    int n = Z_Matrix.getColumns();

    Matrix result = Matrix(m, n);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){

            result.setData(i,j,(*activationtype)(result.getValue(i,j)));

        }
    }

    return Matrix(0, 0);


};

double Relu::activate(double x)
{
    return std::max(x, 0.0);
}

double Relu::activate_derivative(double x)
{
    if(x > 0.0){
        return 1.0;
    } else{
        return 0.0;
    }
}
