//
// Created by Gryffindor Dodie on 7/27/22.
//

#include "matrix_cpp.h"
#include <iostream>
#include "math.h"

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    int code = 0;
    if (_rows != other._rows) code = 1;
    if (_cols != other._cols) code = 1;
    if (code == 0) {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                if (fabs(_matrix[i][j] - other._matrix[i][j]) > EPS) code = 1;
            }
        }
    }
    return code;
}
void S21Matrix::sum_matrix(const S21Matrix& other) {
    try {
        if ((_rows != other._rows) || (_cols != other._cols)) {
            throw IncorrectSize();
        }
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = other._matrix[i][j] + _matrix[i][j];
            }
        }
    } catch (S21Matrix::IncorrectSize) {
        std::cout << "Incorrect size if matrix!" << std::endl;
    }
}
void S21Matrix::sub_matrix(const S21Matrix& other) {
    try {
        if ((_rows != other._rows) || (_cols != other._cols)) {
            throw IncorrectSize();
        }
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = other._matrix[i][j] - _matrix[i][j];
            }
        }
    } catch (S21Matrix::IncorrectSize) {
        std::cout << "Incorrect size if matrix!" << std::endl;
    }
}
void  S21Matrix::mul_number(const double num) {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = num * _matrix[i][j];
            }
        }
}
void  S21Matrix::mul_matrix(const S21Matrix& other) {
    try {
        if ((_cols != other._rows) || _cols < 1 || _rows < 1 || other._rows < 1 || other._cols < 1) {
            throw IncorrectSize();
        }
        double result[_rows][other._cols];
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < other._cols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < other._rows; k++) {
                    result[i][j] += _matrix[i][k] * other._matrix[k][j];
                }
            }
        }
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = result[i][j];
            }
        }
    } catch (S21Matrix::IncorrectSize) {
        std::cout << "Incorrect size if matrix!" << std::endl;
    }
}
S21Matrix S21Matrix::transpose() {
    S21Matrix result(_rows, _cols);
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            result._matrix[j][i] = _matrix[i][j];
        }
    }
    return result;
}
S21Matrix  S21Matrix::calc_complements() {
    S21Matrix result(_rows, _cols);
    try {
        if ((_rows != _cols) || _rows < 1 || _cols < 1) {
            throw IncorrectSize();
        }
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                double determinant = 0.0;
                S21Matrix minor(_rows - 1, _cols - 1);
                this->fill_minor(minor, i, j);
                determinant = minor.determinant();
                result._matrix[i][j] = pow(-1, i + j) * determinant;
            }
        }
    } catch (S21Matrix::IncorrectSize) {
        std::cout << "Incorrect size of matrix!" << std::endl;
    }
    return result;
}
double  S21Matrix::determinant() {
    int code = 0;
    double result = 0;
    try {
        if ((_cols < 1 || _rows < 1) || (_rows != _cols)) {
            code = 1;
        }
        if (code == 1) throw IncorrectSize();
        if (code == 0 && _cols == 1) {
            result = _matrix[0][0];
        } else if (code == 0 && _cols > 1) {
            result = determinant_rec(_matrix, _rows);
        }
    } catch (S21Matrix::IncorrectSize) {
        std::cout << "Incorrect matrix!" << std::endl;
    }
    return result;
}
S21Matrix  S21Matrix::inverse_matrix() {
    S21Matrix result(_rows, _cols);
    double det = 0.0;
    try {
        if ((_rows == _cols) && _rows > 0 && _cols > 0) {
        } else {
            throw IncorrectSize();
        }
        det = this->determinant();

        S21Matrix tmp(_rows, _cols);
        tmp = this->calc_complements();
        result = tmp.transpose();
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                result._matrix[i][j] = result._matrix[i][j] / det;
            }
        }
    } catch (S21Matrix::IncorrectSize) {
        std::cout << "Incorrect matrix!" << std::endl;
    }
    return result;
}