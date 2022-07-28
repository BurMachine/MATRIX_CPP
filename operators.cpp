//
// Created by Gryffindor Dodie on 7/28/22.
//
#include "matrix_cpp.h"

S21Matrix& S21Matrix::operator =(const S21Matrix& right) {
    for (int i = 0; i < right._rows; i++) {
        for (int j = 0; j < right._cols; j++) {
            this->_matrix[i][j] = right._matrix[i][j];
        }
    }
    return *this;
}

S21Matrix& S21Matrix::operator+(const S21Matrix &right) {
    S21Matrix result(*this);
    result.sum_matrix(right);
    return result;
}
