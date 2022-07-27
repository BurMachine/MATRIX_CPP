//
// Created by Gryffindor Dodie on 7/27/22.
//

#ifndef MATRIX_CPP_MATRIX_CPP_H
#define MATRIX_CPP_MATRIX_CPP_H

class S21Matrix {
private:
    // Attributes
    int _rows, _cols;         // Rows and columns
    double **_matrix;         // Pointer to the memory where the matrix is allocated

public:
    S21Matrix(int rows, int cols) /*: _rows(rows), _cols(cols) */{
        _rows = rows;
        _cols = cols;
        _matrix = new double *[_rows];
        for (int i = 0; i < _rows; i++) {
            _matrix[i] = new double[_cols];
        }
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = 1;
            }
        }
    };              // Default constructor
    ~S21Matrix() {
        for (int i = 0; i  < _rows; i++) {
            delete _matrix[i];
        }
        delete _matrix;
    }             // Destructor

//    void sum_matrix(const S21Matrix& other);
    // Other methods..
    double  getElem(int i, int j);
    void matrix_printer();

    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix calc_complements();
    double determinant();
    S21Matrix inverse_matrix();

};

#endif //MATRIX_CPP_MATRIX_CPP_H
