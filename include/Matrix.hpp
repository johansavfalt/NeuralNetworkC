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

        static std::unique_ptr<Matrix> random(unsigned, unsigned);

        int getColumns();
        int getRows();
        double getValue(unsigned, unsigned );
        std::vector<std::vector<double> > getData();
        void setData(unsigned, unsigned, double);

        void fillwith(int);
        void fillwith(double);
        void show();
        Matrix transpose();
        std::unique_ptr<Matrix> plus(std::unique_ptr<Matrix> &);
        Matrix minus(Matrix &);
        std::unique_ptr<Matrix> getAdjustedMatrix(std::unique_ptr<Matrix> &,const int);
        Matrix minusConstant(double);
        Matrix times(Matrix &);
        Matrix sum();
        Matrix max();
        Matrix hadamanproduct(Matrix &);
        std::unique_ptr<Matrix> product(std::unique_ptr<Matrix> &);
        Matrix timesConstant(double);
};

#endif //NeuralNetworkC_Matrix_H
