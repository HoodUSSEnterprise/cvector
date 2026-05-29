#ifndef RANK_TRACE_MATRIX_H
#define RANK_TRACE_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

// ========== 矩阵的秩（高斯消元法） ==========
int rank_matrixi(MatrixI *m);
int rank_matrixf(MatrixF *m);
int rank_matrixd(MatrixD *m);
int rank_matrixc(MatrixC *m);

// ========== 矩阵的迹（对角线元素之和） ==========
int     trace_matrixi(MatrixI *m);
float   trace_matrixf(MatrixF *m);
double  trace_matrixd(MatrixD *m);
Complex trace_matrixc(MatrixC *m);

#define rank_matrix(m) _Generic((m), \
    MatrixI *: rank_matrixi,         \
    MatrixF *: rank_matrixf,         \
    MatrixD *: rank_matrixd,         \
    MatrixC *: rank_matrixc)(m)

#define trace_matrix(m) _Generic((m), \
    MatrixI *: trace_matrixi,         \
    MatrixF *: trace_matrixf,         \
    MatrixD *: trace_matrixd,         \
    MatrixC *: trace_matrixc)(m)

#endif // RANK_TRACE_MATRIX_H
