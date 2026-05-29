#ifndef SUB_MATRIX_H
#define SUB_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

MatrixI *sub_matrixi_i(MatrixI *m1, MatrixI *m2);

MatrixF *sub_matrixi_f(MatrixI *m1, MatrixF *m2);

MatrixD *sub_matrixi_d(MatrixI *m1, MatrixD *m2);

MatrixC *sub_matrixi_c(MatrixI *m1, MatrixC *m2);

MatrixF *sub_matrixf_i(MatrixF *m1, MatrixI *m2);

MatrixF *sub_matrixf_f(MatrixF *m1, MatrixF *m2);

MatrixD *sub_matrixf_d(MatrixF *m1, MatrixD *m2);

MatrixC *sub_matrixf_c(MatrixF *m1, MatrixC *m2);

MatrixD *sub_matrixd_i(MatrixD *m1, MatrixI *m2);

MatrixD *sub_matrixd_f(MatrixD *m1, MatrixF *m2);

MatrixD *sub_matrixd_d(MatrixD *m1, MatrixD *m2);

MatrixC *sub_matrixd_c(MatrixD *m1, MatrixC *m2);

MatrixC *sub_matrixc_i(MatrixC *m1, MatrixI *m2);

MatrixC *sub_matrixc_f(MatrixC *m1, MatrixF *m2);

MatrixC *sub_matrixc_d(MatrixC *m1, MatrixD *m2);

MatrixC *sub_matrixc_c(MatrixC *m1, MatrixC *m2);

#define sub_matrix(m1, m2) _Generic((m1), \
    MatrixC *: _Generic((m2),           \
        MatrixC *: sub_matrixc_c,      \
        MatrixD *: sub_matrixc_d,      \
        MatrixF *: sub_matrixc_f,      \
        MatrixI *: sub_matrixc_i),     \
    MatrixD *: _Generic((m2),           \
        MatrixC *: sub_matrixd_c,      \
        MatrixD *: sub_matrixd_d,      \
        MatrixF *: sub_matrixd_f,      \
        MatrixI *: sub_matrixd_i),     \
    MatrixF *: _Generic((m2),           \
        MatrixC *: sub_matrixf_c,      \
        MatrixD *: sub_matrixf_d,      \
        MatrixF *: sub_matrixf_f,      \
        MatrixI *: sub_matrixf_i),     \
    MatrixI *: _Generic((m2),           \
        MatrixC *: sub_matrixi_c,      \
        MatrixD *: sub_matrixi_d,      \
        MatrixF *: sub_matrixi_f,      \
        MatrixI *: sub_matrixi_i))(m1, m2)

#endif // SUB_MATRIX_H