#ifndef LU_MATRIX_H
#define LU_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/mul_matrix.h"
#include "matrix/sub_matrix.h"
#include "matrix/determinant_matrix.h"
#include "matrix/transpose_matrix.h"
#include "matrix/special_matrix.h"
#include "complex/operator_complex.h"
#include <math.h>

// ========== 判断能否 LU 分解（所有顺序主子式不为 0） ==========
bool can_lu_decompositioni(MatrixI *m);
bool can_lu_decompositionf(MatrixF *m);
bool can_lu_decompositiond(MatrixD *m);
bool can_lu_decompositionc(MatrixC *m);

// ========== Doolittle 分解 (A = L*U) ==========
// L 为下三角（对角为 1），U 为上三角
// 结果写入 L 和 U（调用者需分配好矩阵空间）
void doolittle_matrixd(MatrixD *m, MatrixD **L, MatrixD **U);

// ========== Cholesky 分解 (A = L*L^T, 仅对称正定) ==========
// L 为下三角矩阵，结果写入 L
void cholesky_matrixd(MatrixD *m, MatrixD **L);

// ========== LDU 分解 (A = L*D*U) ==========
void ldu_matrixd(MatrixD *m, MatrixD **L, MatrixD **D, MatrixD **U);

// ========== Crout 分解 (A = L*U, U 对角为 1) ==========
void crout_matrixd(MatrixD *m, MatrixD **L, MatrixD **U);

#define can_lu_decomposition(m) _Generic((m), \
    MatrixI *: can_lu_decompositioni,         \
    MatrixF *: can_lu_decompositionf,         \
    MatrixD *: can_lu_decompositiond,         \
    MatrixC *: can_lu_decompositionc)(m)

#endif // LU_MATRIX_H