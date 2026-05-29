#ifndef SUBDETERMINANT_MATRIX_H
#define SUBDETERMINANT_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"
#include "matrix/determinant_matrix.h"

// ========== 余子式（移除指定行和列后的子矩阵） ==========

MatrixI *minor_matrixi(MatrixI *m, int row, int col);
MatrixF *minor_matrixf(MatrixF *m, int row, int col);
MatrixD *minor_matrixd(MatrixD *m, int row, int col);
MatrixC *minor_matrixc(MatrixC *m, int row, int col);

// ========== 代数余子式矩阵 ==========

MatrixI *cofactor_matrixi(MatrixI *m);
MatrixF *cofactor_matrixf(MatrixF *m);
MatrixD *cofactor_matrixd(MatrixD *m);
MatrixC *cofactor_matrixc(MatrixC *m);

// ========== Generic 宏 ==========

#define minor_matrix(m, row, col) _Generic((m), \
    MatrixI *: minor_matrixi,                   \
    MatrixF *: minor_matrixf,                   \
    MatrixD *: minor_matrixd,                   \
    MatrixC *: minor_matrixc)(m, row, col)

#define cofactor_matrix(m) _Generic((m), \
    MatrixI *: cofactor_matrixi,         \
    MatrixF *: cofactor_matrixf,         \
    MatrixD *: cofactor_matrixd,         \
    MatrixC *: cofactor_matrixc)(m)

#endif // SUBDETERMINANT_MATRIX_H