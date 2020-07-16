#ifndef NeuralNetworkC_Matrix_H
#define NeuralNetworkC_Matrix_H

#include <vector>

class Matrix
{
    private:
        unsigned M;
        unsigned N;

    public:
        std::vector<std::vector<double>> data;

        Matrix();

        Matrix(unsigned, unsigned);

        static Matrix random(unsigned, unsigned);

        int getColumns();
        int getRows();
        double getValue(unsigned, unsigned );
        std::vector<std::vector<double> > getData();
        void setData(unsigned, unsigned, double);

        void fillwith(int);
        void fillwith(double);
        void show();
        Matrix transpose();
        Matrix plus(Matrix &);
        Matrix minus(Matrix &);
        Matrix getAdjustedMatrix(Matrix &,const int);
        Matrix minusConstant(double);
        Matrix times(Matrix &);
        Matrix sum();
        Matrix max();
        Matrix hadamanproduct(Matrix &);
        Matrix product(Matrix &);
        Matrix timesConstant(double);
        Matrix getRowAsNewMatrix(int);
};


#endif //NeuralNetworkC_Matrix_H
