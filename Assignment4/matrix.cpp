#include <stdexcept>
#include "matrix.h"

using namespace std;

//Default constructor
Matrix::Matrix() : rows(1), cols(1)
{
    matrix = new float* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new float[cols];
    }
    matrix[0][0] = 0;
}

//Main constructor
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    matrix = new float* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(float** a, int rows, int cols) : rows(rows), cols(cols)
{
    matrix = new float* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = a[i][j];
        }
    }
}

//Copy constructor
Matrix::Matrix(const Matrix& m) : rows(m.rows), cols(m.cols)
{
    matrix = new float* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}


//Destructor
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//Operator for output and input
std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    cout << endl;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++)
            os << m.matrix[i][j] << " ";
        os << endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m)
{
    delete[] m.matrix;

    cout << "Enter the number of Rows: ";
    is >> m.rows;
    cout << "Enter the number of Columns: ";
    is >> m.cols;

    m.matrix = new float* [m.rows];
    for (int i = 0; i < m.rows; i++) {
        m.matrix[i] = new float[m.cols];
    }

    cout << "Matrix: " << endl;

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            is >> m.matrix[i][j];
            if (!(isdigit(m.matrix[i][j])) && !(isspace(m.matrix[i][j]))) {
                is.ignore();
            }
            else
                continue;
        }
    }
    return is;
}

//Basic Function Operator
//Copy assignment operator
Matrix& Matrix::operator =(const Matrix& m)
{
    if (this == &m) {
        return *this;
    }

    if (rows != m.rows || cols != m.cols) {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        rows = m.rows;
        cols = m.cols;
        matrix = new float* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new float[cols];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
    return *this;
}

//Move assignment operator
Matrix& Matrix::operator =(Matrix& m)
{
    delete[] matrix;
    this->cols = m.cols;
    this->rows = m.rows;
    this->matrix = m.matrix;

    m.matrix = nullptr;
    m.rows = 0;
    m.cols = 0;
    return *this;
}

//Operator* for matrix multiplication
Matrix& Matrix::operator *(const Matrix& m)
{
    Matrix temp(rows, m.cols);

    if (cols != m.rows) {
        cout << endl << "Invalid sizes of the two input matrices!" << endl;
    }
    else {
        for (int i = 0; i < temp.rows; i++) {
            for (int j = 0; j < temp.cols; j++) {
                for (int k = 0; k < cols; ++k) {
                    temp.matrix[i][j] += (matrix[i][k] * m.matrix[k][j]);
                }
            }
        }
    }
    return (*this = temp);
}

//Operator* for scalar multiplication
Matrix& Matrix::operator *=(float scalar)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
    return *this;
}

//Operator * which able for both direction scalar multiplication
Matrix operator *(const Matrix& m, float scalar)
{
    Matrix temp(m);
    return (temp *= scalar);
}

Matrix operator *(float scalar, const Matrix& m)
{
    return (m * scalar);
}