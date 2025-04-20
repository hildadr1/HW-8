#include "matrix.h"
Matrix::Matrix(): m_rows(0),m_columns(0){
    m_matrix.resize(m_rows, vector<int>(m_columns, 0));
}
Matrix::Matrix(int rows, int columns):
    m_rows(rows),m_columns(columns){
        m_matrix.resize(m_rows, vector<int>(m_columns, 0));
}
void Matrix::add(int rows,int columns, int value){
    if(m_rows >= rows  && m_columns >= columns){
        m_matrix[rows][columns] = value;
    }
}
void Matrix::print(){
    for(unsigned int i = 0; i < m_matrix.size(); i++){
        for(unsigned int j = 0; j < m_matrix[i].size(); j++){
            cout << m_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int& Matrix::at(int row, int col){
    return m_matrix[row][col];
}
const int& Matrix::at(int row, int col) const{
    return m_matrix[row][col];
}
Matrix Matrix::operator+(const Matrix& other){
    if((m_rows == other.m_rows) && (m_columns == other.m_columns)){
        Matrix result(m_rows, m_columns);
        for(unsigned int i = 0; i < m_matrix.size(); i++){
            for(unsigned int j = 0; j < m_matrix[i].size(); j++){
                result.at(i,j) = m_matrix[i][j] + other.at(i,j);
            }
        }
        return result;
    }
    throw invalid_argument("Matrix dimensions must match for addition");
}

Matrix Matrix::operator*(double scalar){
    Matrix result(m_rows, m_columns);
    for(unsigned int i = 0; i < m_matrix.size(); i++){
        for(unsigned int j = 0; j < m_matrix[i].size(); j++){
            result.at(i,j) = m_matrix[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other){
    if(m_columns == other.m_rows){
        Matrix result(m_rows, other.m_columns);
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < other.m_columns; j++){
                for(int x = 0; x < m_columns; x++){
                    result.at(i,j) += m_matrix[i][x] * other.at(x,j);
                }
            }
        }
        return result;
    }
    throw invalid_argument("Matrix A rows must match Matrix B columns");
}

Matrix Matrix::transpose(){
    Matrix result(m_columns, m_rows);
    for(int i = 0; i < m_rows;  i++){
        for(int j = 0; j < m_columns; j++){
            result.at(j,i) = m_matrix[i][j];
        }
    }
    return result;
}


