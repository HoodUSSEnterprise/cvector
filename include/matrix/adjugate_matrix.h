#ifndef ADJUGATE_MATRIX_H
#define ADJUGATE_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/determinant_matrix.h"

MatrixI *adjugate_matrixi(MatrixI *m);
MatrixF *adjugate_matrixf(MatrixF *m);
MatrixD *adjugate_matrixd(MatrixD *m);
MatrixC *adjugate_matrixc(MatrixC *m);

#define adjugate_matrix(m) _Generic((m), \
    MatrixI *: adjugate_matrixi,         \
    MatrixF *: adjugate_matrixf,         \
    MatrixD *: adjugate_matrixd,         \
    MatrixC *: adjugate_matrixc)(m)

#endif // ADJUGATE_MATRIX_H