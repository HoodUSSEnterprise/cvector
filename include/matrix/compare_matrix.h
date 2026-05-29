#ifndef COMPARE_MATRIX_H
#define COMPARE_MATRIX_H

#include <stdbool.h>
#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

bool is_equal_matrixi_i(MatrixI *m1, MatrixI *m2);

bool is_equal_matrixi_f(MatrixI *m1, MatrixF *m2);

bool is_equal_matrixi_d(MatrixI *m1, MatrixD *m2);

bool is_equal_matrixi_c(MatrixI *m1, MatrixC *m2);

bool is_equal_matrixf_f(MatrixF *m1, MatrixF *m2);

bool is_equal_matrixf_i(MatrixF *m1, MatrixI *m2);

bool is_equal_matrixf_d(MatrixF *m1, MatrixD *m2);

bool is_equal_matrixf_c(MatrixF *m1, MatrixC *m2);

bool is_equal_matrixd_d(MatrixD *m1, MatrixD *m2);

bool is_equal_matrixd_i(MatrixD *m1, MatrixI *m2);

bool is_equal_matrixd_f(MatrixD *m1, MatrixF *m2);

bool is_equal_matrixd_c(MatrixD *m1, MatrixC *m2);

bool is_equal_matrixc_c(MatrixC *m1, MatrixC *m2);

bool is_equal_matrixc_i(MatrixC *m1, MatrixI *m2);

bool is_equal_matrixc_f(MatrixC *m1, MatrixF *m2);

bool is_equal_matrixc_d(MatrixC *m1, MatrixD *m2);

#define is_equal_matrix(m1, m2) _Generic((m1), \
    MatrixC *: _Generic((m2),                  \
        MatrixC *: is_equal_matrixc_c,         \
        MatrixD *: is_equal_matrixc_d,         \
        MatrixF *: is_equal_matrixc_f,         \
        MatrixI *: is_equal_matrixc_i),        \
    MatrixD *: _Generic((m2),                  \
        MatrixC *: is_equal_matrixd_c,         \
        MatrixD *: is_equal_matrixd_d,         \
        MatrixF *: is_equal_matrixd_f,         \
        MatrixI *: is_equal_matrixd_i),        \
    MatrixF *: _Generic((m2),                  \
        MatrixC *: is_equal_matrixf_c,         \
        MatrixD *: is_equal_matrixf_d,         \
        MatrixF *: is_equal_matrixf_f,         \
        MatrixI *: is_equal_matrixf_i),        \
    MatrixI *: _Generic((m2),                  \
        MatrixC *: is_equal_matrixi_c,         \
        MatrixD *: is_equal_matrixi_d,         \
        MatrixF *: is_equal_matrixi_f,         \
        MatrixI *: is_equal_matrixi_i))(m1, m2)

#endif // COMPARE_MATRIX_H
