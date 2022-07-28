//
// Created by Gryffindor Dodie on 7/28/22.
//
#include <gtest/gtest.h>
#include "matrix_cpp.h"

TEST(test_eq_matrix, test1) {
    S21Matrix matrix1(3,3);
    S21Matrix matrix2(3,3);
    matrix2.set_num(0, 0, 0);
    EXPECT_EQ(matrix1.eq_matrix(matrix2), 1);
}
TEST(mult_matrix, test2) {
    S21Matrix matrix(2, 2);
    S21Matrix matrix1(2, 2);
    S21Matrix matrix_res(2, 2);
    matrix.set_num(0, 0, 1);
    matrix.set_num(0, 1, 2);
//    matrix.set_num(1, 0, 3);
//    matrix.set_num(1, 1, 4);
    matrix1.set_num(0, 0, 1);
    matrix1.set_num(0, 1, 2);
    matrix1.set_num(1, 0, 3);
    matrix1.set_num(1, 1, 4);

    matrix_res.set_num(0, 0, 7);
    matrix_res.set_num(0, 1, 10);
    matrix_res.set_num(1, 0, 15);
    matrix_res.set_num(1, 1, 22);
    matrix.mul_matrix(matrix1);
    EXPECT_EQ(matrix, matrix_res);
}

TEST(trans, test3) {
    S21Matrix matrix(2, 2);
    S21Matrix matrix1(2, 2);
    matrix.set_num(0, 0, 1);
    matrix.set_num(0, 1, 2);
    matrix.set_num(1, 0, 3);
    matrix.set_num(1, 1, 4);

    matrix1 = matrix.transpose();

    matrix1.matrix_printer();
}

TEST(det, test4) {
    S21Matrix matrix(2, 2);
    S21Matrix matrix1(1, 1);
    matrix.set_num(0, 0, 1);
    matrix.set_num(0, 1, 2);
    matrix.set_num(1, 0, 3);
    matrix.set_num(1, 1, 4);

    double a = matrix.determinant();
    EXPECT_EQ(matrix, matrix_res);
}

TEST(calc, test5) {
    S21Matrix matrix(2, 2);
    S21Matrix matrix1(2, 2);
    matrix.set_num(0, 0, 1);
    matrix.set_num(0, 1, 2);
    matrix.set_num(1, 0, 3);
    matrix.set_num(1, 1, 4);

    matrix1 = matrix.calc_complements();
    EXPECT_EQ(matrix, matrix_res);
}

TEST(calc, test6) {
//    std::cout << "Hello, World!" << std::endl;
    S21Matrix matrix(2, 2);
    S21Matrix matrix1(2, 2);
    matrix.set_num(0, 0, 1);
    matrix.set_num(0, 1, 2);
    matrix.set_num(1, 0, 3);
    matrix.set_num(1, 1, 4);
    matrix1 = matrix.inverse_matrix();
    EXPECT_EQ(matrix, matrix_res);
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
