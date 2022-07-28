//
// Created by Gryffindor Dodie on 7/28/22.
//

#include "matrix_cpp.h"
#include <iostream>

double S21Matrix::get_num(int i, int j) {
    return _matrix[i][j];
}

void S21Matrix::set_num(int i, int j, double num) {
    _matrix[i][j] = num;
}

void S21Matrix::fill_minor(S21Matrix& minor, int i, int j) {
    int minor_row_index = 0;
    int minor_column_index = 0;
    for (int m = 0; m < _rows; m++) {
        for (int n = 0; n < _cols; n++) {
            if (m != i && n != j) {
                minor._matrix[minor_row_index][minor_column_index] = _matrix[m][n];

                if (minor_column_index + 1 != minor._cols) {
                    minor_column_index++;
                } else {
                    minor_row_index++;
                    minor_column_index = 0;
                }
            }
        }
    }
}

double S21Matrix::determinant_rec(double **matrix, int dim) {
    if (dim == 1) return matrix[0][0];

    int code = 0;
    double det = 0.0;
    double sign = 1.0;
    try {
        for (int i = 0; i < dim; i++) {
//        matrix_t tmp = {0};
//        int code = s21_create_matrix(dim - 1, dim - 1, &tmp);
            if (dim < 1) code = 1;
            S21Matrix tmp(dim - 1, dim - 1);
            if (code == 1)
                throw IncorrectSize();
            for (int m = 1; m < dim; m++) {
                int p = 0;
                for (int n = 0; n < dim; n++) {
                    if (n == i)
                        continue;
                    tmp._matrix[m - 1][p] = matrix[m][n];
                    p++;
                }
            }

            det += sign * matrix[0][i] * determinant_rec(tmp._matrix, dim - 1);
            sign = -sign;
//        s21_remove_matrix(&tmp);
//            tmp.~S21Matrix();
        }
    } catch (S21Matrix::IncorrectSize) {
        std::cout << "Incorrect size" << std::endl;
    }

    return det;
}