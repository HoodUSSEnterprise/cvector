#ifndef CREATE_MATRIX_H
#define CREATE_MATRIX_H

#include "matrix/base_matrix.h"

MatrixI *create_matrixi_i(int rows, int cols, int *data, size_t len);

MatrixI *create_matrixi_f(int rows, int cols, float *data, size_t len);

MatrixI *create_matrixi_d(int rows, int cols, double *data, size_t len);

MatrixI *create_matrixi_c(int rows, int cols, Complex *data, size_t len);

MatrixF *create_matrixf_i(int rows, int cols, int *data, size_t len);

MatrixF *create_matrixf_f(int rows, int cols, float *data, size_t len);

MatrixF *create_matrixf_d(int rows, int cols, double *data, size_t len);

MatrixF *create_matrixf_c(int rows, int cols, Complex *data, size_t len);

MatrixD *create_matrixd_i(int rows, int cols, int *data, size_t len);

MatrixD *create_matrixd_f(int rows, int cols, float *data, size_t len);

MatrixD *create_matrixd_d(int rows, int cols, double *data, size_t len);

MatrixD *create_matrixd_c(int rows, int cols, Complex *data, size_t len);

MatrixC *create_matrixc_i(int rows, int cols, int *data, size_t len);

MatrixC *create_matrixc_f(int rows, int cols, float *data, size_t len);

MatrixC *create_matrixc_d(int rows, int cols, double *data, size_t len);

MatrixC *create_matrixc_c(int rows, int cols, Complex *data, size_t len);

#define create_matrixi(rows, cols, data, len) _Generic((data), \
    int *: create_matrixi_i,                                   \
    float *: create_matrixi_f,                                 \
    double *: create_matrixi_d,                                \
    Complex *:create_matrixi_c)(rows, cols, data, len)

#define create_matrixf(rows, cols, data, len) _Generic((data), \
    int *: create_matrixf_i,                                   \
    float *: create_matrixf_f,                                 \
    double *: create_matrixf_d,                                \
    Complex *:create_matrixf_c)(rows, cols, data, len)

#define create_matrixd(rows, cols, data, len) _Generic((data), \
    int *: create_matrixd_i,                                   \
    float *: create_matrixd_f,                                 \
    double *: create_matrixd_d,                                \
    Complex *:create_matrixd_c)(rows, cols, data, len)

#define create_matrixc(rows, cols, data, len) _Generic((data), \
    int *: create_matrixc_i,                                   \
    float *: create_matrixc_f,                                 \
    double *: create_matrixc_d,                                \
    Complex *:create_matrixc_c)(rows, cols, data, len)

#endif // CREATE_MATRIX_H