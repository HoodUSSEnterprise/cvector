#ifndef SCALAR_MUL_MATRIX_H
#define SCALAR_MUL_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

// 矩阵数乘：m * scalar
MatrixI *scalar_mul_matrixi_i(MatrixI *m, int s);

MatrixF *scalar_mul_matrixi_f(MatrixI *m, float s);

MatrixD *scalar_mul_matrixi_d(MatrixI *m, double s);

MatrixC *scalar_mul_matrixi_c(MatrixI *m, Complex s);

MatrixF *scalar_mul_matrixf_i(MatrixF *m, int s);

MatrixF *scalar_mul_matrixf_f(MatrixF *m, float s);

MatrixD *scalar_mul_matrixf_d(MatrixF *m, double s);

MatrixC *scalar_mul_matrixf_c(MatrixF *m, Complex s);

MatrixD *scalar_mul_matrixd_i(MatrixD *m, int s);

MatrixD *scalar_mul_matrixd_f(MatrixD *m, float s);

MatrixD *scalar_mul_matrixd_d(MatrixD *m, double s);

MatrixC *scalar_mul_matrixd_c(MatrixD *m, Complex s);

MatrixC *scalar_mul_matrixc_i(MatrixC *m, int s);

MatrixC *scalar_mul_matrixc_f(MatrixC *m, float s);

MatrixC *scalar_mul_matrixc_d(MatrixC *m, double s);

MatrixC *scalar_mul_matrixc_c(MatrixC *m, Complex s);

#define scalar_mul_matrix(m, s) _Generic((m), \
    MatrixC *: _Generic((s),                  \
        int: scalar_mul_matrixc_i,            \
        float: scalar_mul_matrixc_f,          \
        double: scalar_mul_matrixc_d,         \
        Complex: scalar_mul_matrixc_c),       \
    MatrixD *: _Generic((s),                  \
        int: scalar_mul_matrixd_i,            \
        float: scalar_mul_matrixd_f,          \
        double: scalar_mul_matrixd_d,         \
        Complex: scalar_mul_matrixd_c),       \
    MatrixF *: _Generic((s),                  \
        int: scalar_mul_matrixf_i,            \
        float: scalar_mul_matrixf_f,          \
        double: scalar_mul_matrixf_d,         \
        Complex: scalar_mul_matrixf_c),       \
    MatrixI *: _Generic((s),                  \
        int: scalar_mul_matrixi_i,            \
        float: scalar_mul_matrixi_f,          \
        double: scalar_mul_matrixi_d,         \
        Complex: scalar_mul_matrixi_c))(m, s)

#endif // SCALAR_MUL_MATRIX_H
