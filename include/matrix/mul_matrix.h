#ifndef MUL_MATRIX_H
#define MUL_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

MatrixI *mul_matrixi_i(MatrixI *m1, MatrixI *m2);

MatrixF *mul_matrixi_f(MatrixI *m1, MatrixF *m2);

MatrixD *mul_matrixi_d(MatrixI *m1, MatrixD *m2);

MatrixC *mul_matrixi_c(MatrixI *m1, MatrixC *m2);

MatrixF *mul_matrixf_i(MatrixF *m1, MatrixI *m2);

MatrixF *mul_matrixf_f(MatrixF *m1, MatrixF *m2);

MatrixD *mul_matrixf_d(MatrixF *m1, MatrixD *m2);

MatrixC *mul_matrixf_c(MatrixF *m1, MatrixC *m2);

MatrixD *mul_matrixd_i(MatrixD *m1, MatrixI *m2);

MatrixD *mul_matrixd_f(MatrixD *m1, MatrixF *m2);

MatrixD *mul_matrixd_d(MatrixD *m1, MatrixD *m2);

MatrixC *mul_matrixd_c(MatrixD *m1, MatrixC *m2);

MatrixC *mul_matrixc_i(MatrixC *m1, MatrixI *m2);

MatrixC *mul_matrixc_f(MatrixC *m1, MatrixF *m2);

MatrixC *mul_matrixc_d(MatrixC *m1, MatrixD *m2);

MatrixC *mul_matrixc_c(MatrixC *m1, MatrixC *m2);

#define mul_matrix(m1, m2) _Generic((m1), \
    MatrixC *: _Generic((m2),           \
        MatrixC *: mul_matrixc_c,      \
        MatrixD *: mul_matrixc_d,      \
        MatrixF *: mul_matrixc_f,      \
        MatrixI *: mul_matrixc_i),     \
    MatrixD *: _Generic((m2),           \
        MatrixC *: mul_matrixd_c,      \
        MatrixD *: mul_matrixd_d,      \
        MatrixF *: mul_matrixd_f,      \
        MatrixI *: mul_matrixd_i),     \
    MatrixF *: _Generic((m2),           \
        MatrixC *: mul_matrixf_c,      \
        MatrixD *: mul_matrixf_d,      \
        MatrixF *: mul_matrixf_f,      \
        MatrixI *: mul_matrixf_i),     \
    MatrixI *: _Generic((m2),           \
        MatrixC *: mul_matrixi_c,      \
        MatrixD *: mul_matrixi_d,      \
        MatrixF *: mul_matrixi_f,      \
        MatrixI *: mul_matrixi_i))(m1, m2)


#endif // MUL_MATRIX_H