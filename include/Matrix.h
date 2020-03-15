#pragma once
#include <vector>

using namespace std;

class Matrix
{
    private:
        unsigned M;
        unsigned N;

    public:
        vector<vector<double>> data;

        Matrix(unsigned, unsigned);
        Matrix(vector<vector<double> > data);
        static Matrix random(unsigned, unsigned);

        int getColumns();
        int getRows();
        double getValue(unsigned, unsigned );
        vector<vector<double> > getData();
        void setData(unsigned, unsigned, double);

        void fillwith(int);
        void fillwith(double);
        void show();
        void init();
        Matrix transpose();
        Matrix plus(Matrix &);
        Matrix minus(Matrix &);
        Matrix getAdjustedMatrix(Matrix &, int);
        Matrix minusConstant(double);
        Matrix times(Matrix &);
        Matrix sum();
        Matrix max();
        Matrix hadamanproduct(Matrix &);
        Matrix product(Matrix &);
        Matrix timesConstant(double);
};
