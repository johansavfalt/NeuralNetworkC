#include "../include/Training.hpp"
#include "../include/Matrix.hpp"
#include <math.h>
#include <list>
#include <iostream>

Matrix Training::compute_cross_entropy_loss(Matrix &data, Matrix &test, bool derivative)
{
    if(derivative){
        return data.minus(test);
    } else{
        return cross_entropy_loss(data, test);
    }

}

Matrix Training::cross_entropy_loss(Matrix &predictDistribution, Matrix &trueDistribution){

    double error = 0.0;
    int M =predictDistribution.getRows();

    std::vector<double> batchResult;


    for(int i = 0; i < M; i++){

        double singleTrue = trueDistribution.getValue(0, i);
        double singlePred = predictDistribution.getValue(i, 0);


        if(singleTrue == 1){
            error = log(singlePred) * -1.0;
        } else{
            error = log(1.0 - singlePred) * -1.0;
        }
        
        batchResult.push_back(error);
    }

    for(auto x:batchResult){

        error += x;
    }


    double doubleValue = (1.0/M * error);
    Matrix result(1, 1);
    result.fillwith(error);
    return result;
}
