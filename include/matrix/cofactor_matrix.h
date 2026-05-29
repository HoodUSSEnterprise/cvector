#ifndef COFACTOR_MATRIX_H
#define COFACTOR_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/determinant_matrix.h"

// ========== 代数余子式矩阵 ==========

MatrixI *cofactor_matrixi(MatrixI *m);
MatrixF *cofactor_matrixf(MatrixF *m);
MatrixD *cofactor_matrixd(MatrixD *m);
MatrixC *cofactor_matrixc(MatrixC *m);

#define cofactor_matrix(m) _Generic((m), \
    MatrixI *: cofactor_matrixi,         \
    MatrixF *: cofactor_matrixf,         \
    MatrixD *: cofactor_matrixd,         \
    MatrixC *: cofactor_matrixc)(m)

#endif // COFACTOR_MATRIX_H