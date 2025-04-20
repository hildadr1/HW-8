#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
using namespace std;

class Matrix{
public:
    Matrix();
    Matrix(int rows, int columns);
    void add(int rows, int columns, int value);
    void print();
    int& at(int row, int col);
    const int& at(int row, int col) const;
    Matrix operator+(const Matrix& other);
    Matrix operator*(double scalar);
    Matrix operator*(const Matrix& other);
    Matrix transpose();
private:
    int m_rows;
    int m_columns;
    vector<vector<int>> m_matrix;
};
#endif