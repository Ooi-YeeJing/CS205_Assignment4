#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Matrix {

private:
    int rows, cols;
    float** matrix;

public:
    //constructor
    Matrix();
    Matrix(int rows, int cols);
    Matrix(float** matrix, int rows, int cols);
    Matrix(const Matrix& m);
    //destructor
    ~Matrix();

    //basic function operator
    Matrix& operator =(const Matrix& m);
    Matrix& operator =(Matrix& m);
    Matrix& operator *(const Matrix& m);
    Matrix& operator *=(float scalar);
    friend Matrix operator*(const Matrix& m, float scalar);
    friend Matrix operator*(float scalar, const Matrix& m);
    friend std::ostream& operator<<(std::ostream& os, const  Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
};

#endif