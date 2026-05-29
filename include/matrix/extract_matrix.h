#ifndef EXTRACT_MATRIX_H
#define EXTRACT_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"
#include "matrix/create_matrix.h"

// ========== 提取列向量（返回 n×1 矩阵） ==========
MatrixI *col_vector_matrixi(MatrixI *m, int index);
MatrixF *col_vector_matrixf(MatrixF *m, int index);
MatrixD *col_vector_matrixd(MatrixD *m, int index);
MatrixC *col_vector_matrixc(MatrixC *m, int index);

// ========== 获取对角线元素（返回动态数组） ==========
int     *get_diag_matrixi(MatrixI *m);
float   *get_diag_matrixf(MatrixF *m);
double  *get_diag_matrixd(MatrixD *m);
Complex *get_diag_matrixc(MatrixC *m);

#define col_vector_matrix(m, index) _Generic((m), \
    MatrixI *: col_vector_matrixi,                \
    MatrixF *: col_vector_matrixf,                \
    MatrixD *: col_vector_matrixd,                \
    MatrixC *: col_vector_matrixc)(m, index)

#define get_diag_matrix(m) _Generic((m), \
    MatrixI *: get_diag_matrixi,         \
    MatrixF *: get_diag_matrixf,         \
    MatrixD *: get_diag_matrixd,         \
    MatrixC *: get_diag_matrixc)(m)

#endif // EXTRACT_MATRIX_H
