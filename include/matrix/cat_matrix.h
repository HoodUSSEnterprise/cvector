#ifndef CAT_MATRIX_H
#define CAT_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

// int 与其他类型连接
MatrixI *cat_matrixi_i(MatrixI *m1, MatrixI *m2, int axis);
MatrixF *cat_matrixi_f(MatrixI *m1, MatrixF *m2, int axis);
MatrixD *cat_matrixi_d(MatrixI *m1, MatrixD *m2, int axis);
MatrixC *cat_matrixi_c(MatrixI *m1, MatrixC *m2, int axis);

// float 与其他类型连接
MatrixF *cat_matrixf_f(MatrixF *m1, MatrixF *m2, int axis);
MatrixF *cat_matrixf_i(MatrixF *m1, MatrixI *m2, int axis);
MatrixD *cat_matrixf_d(MatrixF *m1, MatrixD *m2, int axis);
MatrixC *cat_matrixf_c(MatrixF *m1, MatrixC *m2, int axis);

// double 与其他类型连接
MatrixD *cat_matrixd_d(MatrixD *m1, MatrixD *m2, int axis);
MatrixD *cat_matrixd_i(MatrixD *m1, MatrixI *m2, int axis);
MatrixD *cat_matrixd_f(MatrixD *m1, MatrixF *m2, int axis);
MatrixC *cat_matrixd_c(MatrixD *m1, MatrixC *m2, int axis);

// Complex 与其他类型连接
MatrixC *cat_matrixc_c(MatrixC *m1, MatrixC *m2, int axis);
MatrixC *cat_matrixc_i(MatrixC *m1, MatrixI *m2, int axis);
MatrixC *cat_matrixc_f(MatrixC *m1, MatrixF *m2, int axis);
MatrixC *cat_matrixc_d(MatrixC *m1, MatrixD *m2, int axis);

#define cat_matrix(m1, m2, axis) _Generic((m1), \
    MatrixC *: _Generic((m2),                   \
        MatrixC *: cat_matrixc_c,               \
        MatrixD *: cat_matrixc_d,               \
        MatrixF *: cat_matrixc_f,               \
        MatrixI *: cat_matrixc_i),              \
    MatrixD *: _Generic((m2),                   \
        MatrixC *: cat_matrixd_c,               \
        MatrixD *: cat_matrixd_d,               \
        MatrixF *: cat_matrixd_f,               \
        MatrixI *: cat_matrixd_i),              \
    MatrixF *: _Generic((m2),                   \
        MatrixC *: cat_matrixf_c,               \
        MatrixD *: cat_matrixf_d,               \
        MatrixF *: cat_matrixf_f,               \
        MatrixI *: cat_matrixf_i),              \
    MatrixI *: _Generic((m2),                   \
        MatrixC *: cat_matrixi_c,               \
        MatrixD *: cat_matrixi_d,               \
        MatrixF *: cat_matrixi_f,               \
        MatrixI *: cat_matrixi_i))(m1, m2, axis)

#endif // CAT_MATRIX_H