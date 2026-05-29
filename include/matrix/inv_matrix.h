#ifndef INV_MATRIX_H
#define INV_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

MatrixD *inv_matrixi(MatrixI *m);

MatrixD *inv_matrixf(MatrixF *m);

MatrixD *inv_matrixd(MatrixD *m);

MatrixC *inv_matrixc(MatrixC *m);

#define inv_matrix(x) _Generic((x), \
    MatrixI *: inv_matrixi,         \
    MatrixF *: inv_matrixf,         \
    MatrixD *: inv_matrixd,         \
    MatrixC *: inv_matrixc)(x)

#endif // INV_MATRIX_H