#ifndef SUBDETERMINANT_MATRIX_H
#define SUBDETERMINANT_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

int det_matrixi(MatrixI *m);
float det_matrixf(MatrixF *m);
double det_matrixd(MatrixD *m);
Complex det_matrixc(MatrixC *m);

MatrixI *minor_matrixi(MatrixI *m, int row, int col);
MatrixF *minor_matrixf(MatrixF *m, int row, int col);
MatrixD *minor_matrixd(MatrixD *m, int row, int col);
MatrixC *minor_matrixc(MatrixC *m, int row, int col);

#define minor_matrix(m, row, col) _Generic((m), \
    MatrixI *: minor_matrixi,                   \
    MatrixF *: minor_matrixf,                   \
    MatrixD *: minor_matrixd,                   \
    MatrixC *: minor_matrixc)(m, row, col)

#define det_matrix(m) _Generic((m), \
    MatrixI *: det_matrixi,         \
    MatrixF *: det_matrixf,         \
    MatrixD *: det_matrixd,         \
    MatrixC *: det_matrixc)(m)

#endif // SUBDETERMINANT_MATRIX_H