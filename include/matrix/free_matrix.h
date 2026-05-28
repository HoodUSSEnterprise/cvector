#ifndef FREE_MATRIX_H
#define FREE_MATRIX_H

#include "matrix/base_matrix.h"

void free_matrixi(MatrixI *m);

void free_matrixf(MatrixF *m);

void free_matrixd(MatrixD *m);

void free_matrixc(MatrixC *m);

#define free_matrix(x) _Generic((x), \
    MatrixI *: free_matrixi,         \
    MatrixF *: free_matrixf,         \
    MatrixD *: free_matrixd,         \
    MatrixC *: free_matrixc)(x)

#endif // FREE_MATRIX_H