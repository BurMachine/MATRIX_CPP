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
    S21Matrix matrix(10, 10);
    matrix.matrix_printer();
    return 0;
}
