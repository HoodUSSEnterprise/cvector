#ifndef COPY_MATRIX_H
#define COPY_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/create_matrix.h"

MatrixI *copy_matrixi(MatrixI *m);

MatrixF *copy_matrixf(MatrixF *m);

MatrixD *copy_matrixd(MatrixD *m);

MatrixC *copy_matrixc(MatrixC *m);

#define copy_matrix(m) _Generic((m), \
    MatrixI *: copy_matrixi,         \
    MatrixF *: copy_matrixf,         \
    MatrixD *: copy_matrixd,         \
    MatrixC *: copy_matrixc)(m)

#endif // COPY_MATRIX_H