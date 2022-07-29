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
    result.matrix_printer();
    return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix &right) {
    sum_matrix(right);
    return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix &right) {
    sub_matrix(right);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix &right) {
    mul_matrix(right);
    return *this;
}

bool& S21Matrix::operator==(const S21Matrix &right) {
    bool code = eq_matrix(right);
    return code;
}

//double S21Matrix::operator(index_i,index_j)int index_i, int index_j) {
//    double res = _matrix[index_i][index_j];
//    return res;
//}