#ifndef DETERMINANT_MATRIX_H
#define DETERMINANT_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"

int det_matrixi(MatrixI *m);
float det_matrixf(MatrixF *m);
double det_matrixd(MatrixD *m);
Complex det_matrixc(MatrixC *m);

#define det_matrix(m) _Generic((m), \
    MatrixI *: det_matrixi,         \
    MatrixF *: det_matrixf,         \
    MatrixD *: det_matrixd,         \
    MatrixC *: det_matrixc)(m)

#endif // DETERMINANT_MATRIX_H