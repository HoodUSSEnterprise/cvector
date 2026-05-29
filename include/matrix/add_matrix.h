#ifndef ADD_MATRIX_H
#define ADD_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

MatrixI *add_matrixi_i(MatrixI *m1, MatrixI *m2);

MatrixF *add_matrixi_f(MatrixI *m1, MatrixF *m2);

MatrixD *add_matrixi_d(MatrixI *m1, MatrixD *m2);

MatrixC *add_matrixi_c(MatrixI *m1, MatrixC *m2);

MatrixF *add_matrixf_i(MatrixF *m1, MatrixI *m2);

MatrixF *add_matrixf_f(MatrixF *m1, MatrixF *m2);

MatrixD *add_matrixf_d(MatrixF *m1, MatrixD *m2);

MatrixC *add_matrixf_c(MatrixF *m1, MatrixC *m2);

MatrixD *add_matrixd_i(MatrixD *m1, MatrixI *m2);

MatrixD *add_matrixd_f(MatrixD *m1, MatrixF *m2);

MatrixD *add_matrixd_d(MatrixD *m1, MatrixD *m2);

MatrixC *add_matrixd_c(MatrixD *m1, MatrixC *m2);

MatrixC *add_matrixc_i(MatrixC *m1, MatrixI *m2);

MatrixC *add_matrixc_f(MatrixC *m1, MatrixF *m2);

MatrixC *add_matrixc_d(MatrixC *m1, MatrixD *m2);

MatrixC *add_matrixc_c(MatrixC *m1, MatrixC *m2);

#define add_matrix(m1, m2) _Generic((m1), \
    MatrixC *: _Generic((m2),           \
        MatrixC *: add_matrixc_c,      \
        MatrixD *: add_matrixc_d,      \
        MatrixF *: add_matrixc_f,      \
        MatrixI *: add_matrixc_i),     \
    MatrixD *: _Generic((m2),           \
        MatrixC *: add_matrixd_c,      \
        MatrixD *: add_matrixd_d,      \
        MatrixF *: add_matrixd_f,      \
        MatrixI *: add_matrixd_i),     \
    MatrixF *: _Generic((m2),           \
        MatrixC *: add_matrixf_c,      \
        MatrixD *: add_matrixf_d,      \
        MatrixF *: add_matrixf_f,      \
        MatrixI *: add_matrixf_i),     \
    MatrixI *: _Generic((m2),           \
        MatrixC *: add_matrixi_c,      \
        MatrixD *: add_matrixi_d,      \
        MatrixF *: add_matrixi_f,      \
        MatrixI *: add_matrixi_i))(m1, m2)

#endif // ADD_MATRIX_H