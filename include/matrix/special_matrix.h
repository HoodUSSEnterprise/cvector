#ifndef SPECIAL_MATRIX_H
#define SPECIAL_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/create_matrix.h"

MatrixI *identity_matrixi(int order);

MatrixF *identity_matrixf(int order);

MatrixD *identity_matrixd(int order);

MatrixC *identity_matrixc(int order);

MatrixI *diag_matrixi_i(const int *data, size_t len);

MatrixI *diag_matrixi_f(const float *data, size_t len);

MatrixI *diag_matrixi_d(const double *data, size_t len);

MatrixI *diag_matrixi_c(const Complex *data, size_t len);

MatrixF *diag_matrixf_i(const int *data, size_t len);

MatrixF *diag_matrixf_f(const float *data, size_t len);

MatrixF *diag_matrixf_d(const double *data, size_t len);

MatrixF *diag_matrixf_c(const Complex *data, size_t len);

MatrixD *diag_matrixd_i(const int *data, size_t len);

MatrixD *diag_matrixd_f(const float *data, size_t len);

MatrixD *diag_matrixd_d(const double *data, size_t len);

MatrixD *diag_matrixd_c(const Complex *data, size_t len);

MatrixC *diag_matrixc_i(const int *data, size_t len);

MatrixC *diag_matrixc_f(const float *data, size_t len);

MatrixC *diag_matrixc_d(const double *data, size_t len);

MatrixC *diag_matrixc_c(const Complex *data, size_t len);

MatrixI *eye_matrixi(int rows, int cols);

MatrixF *eye_matrixf(int rows, int cols);

MatrixD *eye_matrixd(int rows, int cols);

MatrixC *eye_matrixc(int rows, int cols);

#define diag_matrixi(data, len) _Generic((data), \
    int *: diag_matrixi_i,            \
    float *: diag_matrixi_f,          \
    double *: diag_matrixi_d,         \
    Complex *: diag_matrixi_c)(data, len)

#define diag_matrixf(data, len) _Generic((data), \
    int *: diag_matrixf_i,            \
    float *: diag_matrixf_f,          \
    double *: diag_matrixf_d,         \
    Complex *: diag_matrixf_c)(data, len)

#define diag_matrixd(data, len) _Generic((data), \
    int *: diag_matrixd_i,            \
    float *: diag_matrixd_f,          \
    double *: diag_matrixd_d,         \
    Complex *: diag_matrixd_c)(data, len)

#define diag_matrixc(data, len) _Generic((data), \
    int *: diag_matrixc_i,            \
    float *: diag_matrixc_f,          \
    double *: diag_matrixc_d,         \
    Complex *: diag_matrixc_c)(data, len)

#endif // SPECIAL_MATRIX_H