#ifndef MATRIX2_H
#define MATRIX2_H
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int m_rows;
    int m_columns;
    int* m_data;
} Matrix;

Matrix create(int rows, int cols);
Matrix clear(Matrix* matrix);

Matrix matrixAddition(const Matrix* matrixOne, const Matrix* matrixTwo);
Matrix matrixScalar(const Matrix* matrix, int scalar);
Matrix matrixMultiply(const Matrix*matrixOne, const Matrix* matrixTwo);
Matrix matrixTranspose(const Matrix* matrix);
void addingElements(Matrix* matrix, int rows, int columns, int value);
// int getIndex(const Matrix* matrix, int row, int col);
void print(const Matrix* matrix);

#endif