#ifndef TRANSPOSE_MATRIX_H
#define TRANSPOSE_MATRIX_H

#include "matrix/base_matrix.h"

MatrixI *transpose_matrixi(MatrixI *m);
MatrixF *transpose_matrixf(MatrixF *m);
MatrixD *transpose_matrixd(MatrixD *m);
MatrixC *transpose_matrixc(MatrixC *m);

#define transpose_matrix(m) _Generic((m), \
    MatrixI *: transpose_matrixi,         \
    MatrixF *: transpose_matrixf,         \
    MatrixD *: transpose_matrixd,         \
    MatrixC *: transpose_matrixc)(m)

#endif // TRANSPOSE_MATRIX_H
