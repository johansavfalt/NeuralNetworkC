#include "../../include/Matrix.h"

class ActivationFunction{

    virtual Matrix activation(Matrix Z_Matrix) = 0;
    virtual Matrix activation_derivative(Matrix &Z_Matrix) = 0;


};
