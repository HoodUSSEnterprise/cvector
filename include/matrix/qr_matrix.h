#ifndef QR_MATRIX_H
#define QR_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/special_matrix.h"
#include "matrix/mul_matrix.h"
#include "matrix/sub_matrix.h"
#include "matrix/transpose_matrix.h"
#include "matrix/extract_matrix.h"
#include "matrix/scalar_mul_matrix.h"
#include "complex/operator_complex.h"
#include <math.h>

// ========== Gram-Schmidt 正交化（返回标准正交基列向量矩阵） ==========
// cols 为输出矩阵，每一列是一个标准正交基
void gram_schmidt_matrixd(MatrixD *m, MatrixD **Q);
void gram_schmidt_matrixc(MatrixC *m, MatrixC **Q);

// ========== QR 分解 - Gram-Schmidt 方法 ==========
void qr_gs_matrixd(MatrixD *m, MatrixD **Q, MatrixD **R);
void qr_gs_matrixc(MatrixC *m, MatrixC **Q, MatrixC **R);

// ========== QR 分解 - Householder 方法 ==========
void qr_householder_matrixd(MatrixD *m, MatrixD **Q, MatrixD **R);
void qr_householder_matrixc(MatrixC *m, MatrixC **Q, MatrixC **R);

// ========== QR 迭代是否收敛（次对角线是否接近 0） ==========
bool qr_iter_stop_matrixd(const MatrixD *m);
bool qr_iter_stop_matrixc(const MatrixC *m);

#endif // QR_MATRIX_H
