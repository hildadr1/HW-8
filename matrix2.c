#include "matrix2.h"
Matrix create(int rows, int cols){
    Matrix matrix;
    matrix.m_rows = rows;
    matrix.m_columns = cols;
    matrix.m_data = (int*)calloc((rows * cols), sizeof(int));
    return matrix;
}

Matrix clear(Matrix* matrix){
    if(matrix!= NULL){
        free(matrix->m_data);
        matrix->m_data = NULL;
        free(matrix);
        matrix = NULL;
    }
    matrix->m_rows = 0;
    matrix->m_columns = 0;
    return *matrix;
}

Matrix matrixAddition(const Matrix* matrixOne, const Matrix* matrixTwo){
    if((matrixOne->m_rows == matrixTwo->m_rows) && (matrixOne->m_columns == matrixTwo->m_columns)){
        Matrix result = create(matrixOne->m_rows, matrixOne->m_columns);
        int index = 0;
        for(int i = 0; i < matrixOne->m_rows; i++){
            for(int j = 0; j < matrixOne->m_columns;j++){
                index = i * matrixOne->m_columns + j;
                result.m_data[index] = matrixOne->m_data[index] + matrixTwo->m_data[index];
            }
        }
        return result;
    }
    Matrix empty;
    empty.m_rows = 0;
    empty.m_columns = 0;
    empty.m_data = NULL;
    return empty;
}
Matrix matrixScalar(const Matrix* matrix, int scalar){
    Matrix result = create(matrix->m_rows, matrix->m_columns);
    int index = 0;
    for(int i = 0; i < matrix->m_rows; i++){
        for(int j = 0; j < matrix->m_columns;j++){
            index = i * matrix->m_columns + j;
            result.m_data[index] = matrix->m_data[index] * scalar;
        }
    }
    return result;
}
// Matrix matrixMultiply(const Matrix*matrixOne, const Matrix* matrixTwo){
//     if(matrixOne->m_columns== matrixTwo->m_rows){
//         Matrix result = create(matrixOne->m_rows, matrixTwo->m_columns);
//         int index = 0;    
//         for(int i = 0; i < matrixOne->m_rows; i++){
//             for(int j = 0; j < matrixTwo->m_columns;j++){
//                 index = i * matrixTwo->m_columns + j;
//                 result.m_data[index] = matrixOne->m_data[index] * matrixOne->m_data[index];
//             }
//         }
//         return result;
//     }

// }
Matrix matrixTranspose(const Matrix* matrix){
    Matrix result = create(matrix->m_columns, matrix->m_rows);
    int index = 0;
    int newIndex = 0;
    for(int i = 0; i < matrix->m_rows; i++){
        for(int j = 0; j < matrix->m_columns;j++){
            newIndex = j * matrix->m_columns + i;
            index = i * matrix->m_columns + j;
            result.m_data[newIndex] = matrix->m_data[index];
        }
    }
    return result;
}

void addingElements(Matrix* matrix, int rows, int columns, int value){
    if((matrix != NULL) && (matrix->m_rows >= rows && matrix->m_columns >= columns)){
        matrix->m_data[rows * matrix->m_columns + columns] = value;
    }  
}
// int getIndex(const Matrix* matrix, int rows, int columns){
//     if((matrix != NULL) && (matrix->m_rows >= rows && matrix->m_columns >= columns)){
//         return matrix->m_data[rows*matrix->m_columns + columns];
//     }
//     return 0;
// }

void print(const Matrix* matrix){
    if(matrix != NULL ){
        int index = 0; 
        for(int i = 0; i < matrix->m_rows; i++){
            for(int j = 0; j < matrix->m_columns; j++){
                index = i * matrix->m_columns + j;
                printf("%d", matrix->m_data[index]);
                printf(" ");
            }
            printf("\n");
        }
    }
}
