#pragma once
#include "Exception.h"
#include <iostream>
using namespace std;

class Matrix
{
protected:
    unsigned m, n;
    int** data;
public:
    Matrix(unsigned rows, unsigned columns);
    Matrix(const Matrix& ob);
    Matrix();
    ~Matrix();

    friend Matrix operator+(Matrix& a, Matrix& b);
    friend istream& operator >> (istream&, Matrix&);
    friend ostream& operator << (ostream&, Matrix);
};