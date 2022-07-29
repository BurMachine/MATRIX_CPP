//
// Created by Gryffindor Dodie on 7/27/22.
//

#ifndef MATRIX_CPP_MATRIX_CPP_H
#define MATRIX_CPP_MATRIX_CPP_H

//S21Matrix ss1, s2;
//....//
//ss1.eq_matrix(s2)
#define EPS 1e-7

class S21Matrix {
        class IncorrectSize { };
    private:
        // Attributes
        int _rows, _cols;         // Rows and columns
        double **_matrix;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix() {
            _rows = 0;
            _cols = 0;
            _matrix = new double *[_rows];
            for (int i = 0; i < _rows; i++) {
                _matrix[i] = new double[_cols];
            }
            _matrix[0][0] = 0;
        }

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
            if (this->_matrix) {
                for (int i = 0; i < _rows; i++) {
                    delete _matrix[i];
                }
                delete _matrix;
            }
        }             // Destructor

        S21Matrix(const S21Matrix& other) { // copy construct
            this->_rows = other._rows;
            this->_cols = other._cols;

            _matrix = new double *[_rows];
            for (int i = 0; i < _rows; i++) {
                _matrix[i] = new double[_cols];
            }

            for (int i = 0; i < other._rows; i++) {
                for (int j = 0; j < other._cols; j++) {
                    _matrix[i][j] = other._matrix[i][j];
                }
            }
        }

        S21Matrix(S21Matrix&& other) {
            this->_rows = other._rows;
            this->_cols = other._cols;

            _matrix = new double *[_rows];
            for (int i = 0; i < _rows; i++) {
                _matrix[i] = new double[_cols];
            }
            for (int i = 0; i < other._rows; i++) {
                for (int j = 0; j < other._cols; j++) {
                    _matrix[i][j] = other._matrix[i][j];
                }
            }

            if (other._matrix) {
                for (int i = 0; i < _rows; i++) {
                    delete other._matrix[i];
                }
                delete other._matrix;
            }
            other._matrix = nullptr;
        }

    //    void sum_matrix(const S21Matrix& other);
        // Other methods..
        double getElem(int i, int j);
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

        // operators
        S21Matrix& operator =(const S21Matrix& other);
        S21Matrix& operator+(const S21Matrix &right);
        S21Matrix& operator+=(const S21Matrix &righ);
        S21Matrix& operator-=(const S21Matrix &righ);
        S21Matrix& operator*=(const S21Matrix &righ);
        bool& operator==(const S21Matrix &righ);

        double get_num(int i, int j);
        void set_num(int i, int j, double num);
        void fill_minor(S21Matrix& minor, int i, int j);
        double determinant_rec(double **matrix, int dim);
//        double& operator[][](int index_i, int index_j);

};

#endif //MATRIX_CPP_MATRIX_CPP_H
