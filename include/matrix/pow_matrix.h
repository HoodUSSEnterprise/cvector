#ifndef POW_MATRIX_H
#define POW_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/mul_matrix.h"
#include "matrix/inv_matrix.h"
#include "matrix/special_matrix.h"

MatrixD *pow_matrixi(MatrixI *m, int index);

MatrixD *pow_matrixf(MatrixF *m, int index);

MatrixD *pow_matrixd(MatrixD *m, int index);

MatrixC *pow_matrixc(MatrixC *m, int index);

#define pow_matrix(x, y) _Generic((x), \
    MatrixI *: pow_matrixi,         \
    MatrixF *: pow_matrixf,         \
    MatrixD *: pow_matrixd,         \
    MatrixC *: pow_matrixc)(x, y)

#endif // POW_MATRIX_H