#ifndef FIND_MATRIX_H
#define FIND_MATRIX_H

#include "matrix/base_matrix.h"
#include "complex/operator_complex.h"
#include <math.h>

typedef struct Pos
{
    int x;
    int y;
} Pos;

extern Pos NonePos;

Pos find_matrixi(MatrixI *m, int elem);

Pos find_matrixf(MatrixF *m, float elem);

Pos find_matrixd(MatrixD *m, double elem);

Pos find_matrixc(MatrixC *m, Complex elem);

#define find_matrix(m, elem) _Generic((m), \
    MatrixI *: find_matrixi,               \
    MatrixF *: find_matrixf,               \
    MatrixD *: find_matrixd,               \
    MatrixC *: find_matrixc)(m, elem)

#endif // FIND_MATRIX_H