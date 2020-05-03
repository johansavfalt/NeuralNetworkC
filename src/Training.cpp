#include "../include/Training.hpp"
#include "../include/Matrix.hpp"
#include <math.h>

Matrix Training::compute_cross_entropy_loss(Matrix &data, int &test, int derivative)
{
    if(derivative){

    } else{
        return cross_entropy_loss(data, test);
    }

}

Matrix Training::cross_entropy_loss(Matrix &predictDistribution, Matrix &trueDistribution){

    double error = 0.0;
    int M =predictDistribution.getRows();
    std::list<double> batchResult;

    for(int i = 0; i < this->M; i++){
        double singleTrue = trueDistribution.getValue(i, 0);
        double singlePred = predictDistribution.getValue(i, 0);
        if(singleTrue == 1){
            error = std::log(singlePred)*-1.0;
        } else{
            error = std::log(1.0 - singlePred) * -1.0;
        }
        batchResult.add(error);
    }
}
