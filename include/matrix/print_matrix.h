#ifndef PRINT_MATRIX_H
#define PRINT_MATRIX_H

#include "matrix/base_matrix.h"

void print_matrixi(MatrixI *m);

void print_matrixf(MatrixF *m);

void print_matrixd(MatrixD *m);

void print_matrixc(MatrixC *m);

#define print_matrix(m) _Generic((m), \
    MatrixI *: print_matrixi,         \
    MatrixF *: print_matrixf,         \
    MatrixD *: print_matrixd,         \
    MatrixC *: print_matrixc)(m)

#endif // PRINT_MATRIX_H