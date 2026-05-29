#ifndef CHECK_MATRIX_H
#define CHECK_MATRIX_H

#include <stdbool.h>
#include "matrix/base_matrix.h"
#include "matrix/transpose_matrix.h"
#include "matrix/mul_matrix.h"
#include "matrix/determinant_matrix.h"
#include "complex/operator_complex.h"

// ========== 判断是否为单位矩阵 ==========
bool is_identity_matrixi(MatrixI *m);
bool is_identity_matrixf(MatrixF *m);
bool is_identity_matrixd(MatrixD *m);
bool is_identity_matrixc(MatrixC *m);

// ========== 判断是否可逆 ==========
bool is_inv_matrixi(MatrixI *m);
bool is_inv_matrixf(MatrixF *m);
bool is_inv_matrixd(MatrixD *m);
bool is_inv_matrixc(MatrixC *m);

// ========== 判断是否为正交矩阵 (A^T * A = I) ==========
bool is_orth_matrixi(MatrixI *m);
bool is_orth_matrixf(MatrixF *m);
bool is_orth_matrixd(MatrixD *m);
bool is_orth_matrixc(MatrixC *m);

// ========== 判断是否为正定矩阵 ==========
bool is_positive_matrixi(MatrixI *m);
bool is_positive_matrixf(MatrixF *m);
bool is_positive_matrixd(MatrixD *m);
bool is_positive_matrixc(MatrixC *m);

#define is_identity_matrix(m) _Generic((m), \
    MatrixI *: is_identity_matrixi,         \
    MatrixF *: is_identity_matrixf,         \
    MatrixD *: is_identity_matrixd,         \
    MatrixC *: is_identity_matrixc)(m)

#define is_inv_matrix(m) _Generic((m), \
    MatrixI *: is_inv_matrixi,         \
    MatrixF *: is_inv_matrixf,         \
    MatrixD *: is_inv_matrixd,         \
    MatrixC *: is_inv_matrixc)(m)

#define is_orth_matrix(m) _Generic((m), \
    MatrixI *: is_orth_matrixi,         \
    MatrixF *: is_orth_matrixf,         \
    MatrixD *: is_orth_matrixd,         \
    MatrixC *: is_orth_matrixc)(m)

#define is_positive_matrix(m) _Generic((m), \
    MatrixI *: is_positive_matrixi,         \
    MatrixF *: is_positive_matrixf,         \
    MatrixD *: is_positive_matrixd,         \
    MatrixC *: is_positive_matrixc)(m)

#endif // CHECK_MATRIX_H
