#ifndef CAT_MATRIX_H
#define CAT_MATRIX_H

#include "matrix/base_matrix.h"

MatrixI *cat_matrixi(MatrixI *m1, MatrixI *m2, int axis);

MatrixF *cat_matrixf(MatrixF *m1, MatrixF *m2, int axis);

MatrixD *cat_matrixd(MatrixD *m1, MatrixD *m2, int axis);

MatrixC *cat_matrixc(MatrixC *m1, MatrixC *m2, int axis);

#define cat_matrix(m1, m2, axis) _Generic((m1), \
    MatrixI *: cat_matrixi,                     \
    MatrixF *: cat_matrixf,                     \
    MatrixD *: cat_matrixd,                     \
    MatrixC *: cat_matrixc)(m1, m2, axis)

#endif // CAT_MATRIX_H