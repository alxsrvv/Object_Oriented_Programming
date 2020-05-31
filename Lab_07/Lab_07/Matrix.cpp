#include "Matrix.h"

Matrix::Matrix()
{
    n = 0;
    m = 0;
    data = NULL;
}

Matrix::Matrix(unsigned rows, unsigned columns)
{
    m = rows;
    n = columns;
   data = new int* [m];
    for (int i = 0; i < m; i++)
       data[i] = new int[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
           data[i][j] = 0;
}

Matrix::Matrix(const Matrix& ob)
{
    m = ob.m;
    n = ob.n;
    if (ob.data == NULL)
    {
       data = NULL;
        return;
    }
   data = new int* [m];
    for (int i = 0; i < m; i++)
       data[i] = new int[n];

    for (unsigned i = 0; i < m; i++)
        for (unsigned j = 0; j < n; j++)
           data[i][j] = ob.data[i][j];
}

Matrix::~Matrix()
{
    if (data != NULL)
    {
        for (unsigned i = 0; i < m; i++)
            delete[]data[i];
        delete[]data;
    }
}

Matrix operator + (Matrix& ob_a, Matrix& ob_b)
{
    if (ob_a.m == ob_b.m && ob_a.n == ob_b.n)
    {
        Matrix temp(ob_a.m, ob_a.n);
        for (int i = 0; i < ob_a.m; i++)
            for (int j = 0; j < ob_a.n; j++)
                temp.data[i][j] = ob_a.data[i][j] + ob_b.data[i][j];
        return temp;
    }
    else
        throw Exception("Dimensions of summable matrices must match!\n");
}

istream& operator >> (istream& in, Matrix& ob)
{
    if (ob.data != NULL)
    {
        for (int i = 0; i < ob.m; i++)
            for (int j = 0; j < ob.n; j++)
                in >> ob.data[i][j];
    }
    return in;
}

ostream& operator << (ostream& out, Matrix ob)
{
    if (ob.data != NULL)
    {
        out << "Matrix:" << endl;
        for (int i = 0; i < ob.m; i++)
        {
            for (int j = 0; j < ob.n; j++)
                out << ob.data[i][j] << "\t";
            out << endl;
        }
    }
    else
        throw Exception("Matrix is empty!\n");
    return out;
}