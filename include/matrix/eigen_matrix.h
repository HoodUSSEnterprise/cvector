#ifndef EIGEN_MATRIX_H
#define EIGEN_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/special_matrix.h"
#include "matrix/qr_matrix.h"
#include "matrix/mul_matrix.h"
#include "matrix/sub_matrix.h"
#include "matrix/copy_matrix.h"
#include "matrix/extract_matrix.h"
#include "matrix/scalar_mul_matrix.h"
#include "complex/operator_complex.h"
#include <math.h>

// ========== 求特征值（QR 迭代法） ==========
double *eigenvalue_matrixd(MatrixD *m);
Complex *eigenvalue_matrixc(MatrixC *m);

// ========== 求特征向量（解 (A - λI)x = 0） ==========
// 返回 n×n 矩阵，每一列为一个特征向量
// 需要 equation 模块支持，暂时返回 NULL
MatrixD *eigenvector_matrixd(MatrixD *m, const double *eigenvalues, int num_ev);

#endif // EIGEN_MATRIX_H
