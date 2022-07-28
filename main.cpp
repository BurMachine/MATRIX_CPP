#include <iostream>
#include "matrix_cpp.h"



void S21Matrix::matrix_printer() {
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_cols; j++) {
            std::cout << this->_matrix[i][j] <<  " ";
        }
        std::cout << std::endl;
    }
}

double  S21Matrix::getElem(int i, int j) {
    return this->_matrix[i][j];
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    S21Matrix matrix(2, 2);
    S21Matrix matrix1(2, 2);
    S21Matrix matrix2(2, 2);
    matrix.set_num(0, 0, 1);
    matrix.set_num(0, 1, 2);
    matrix.set_num(1, 0, 3);
    matrix.set_num(1, 1, 4);

    matrix1.set_num(0, 0, 1);
    matrix1.set_num(0, 1, 2);
    matrix1.set_num(1, 0, 3);
    matrix1.set_num(1, 1, 4);
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 2; j++) {
//
//        }
//    }
//    matrix1 = matrix.inverse_matrix();
matrix2 = (matrix1 + matrix);
//    std::cout << a << std::endl;
    matrix.matrix_printer();
//    matrix1.matrix_printer();
    return 0;
}
