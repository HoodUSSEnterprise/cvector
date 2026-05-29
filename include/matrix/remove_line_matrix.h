#ifndef REMOVE_LINE_MATRIX_H
#define REMOVE_LINE_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/create_matrix.h"
#include "matrix/copy_matrix.h"

MatrixI *remove_matrixi(MatrixI *m, size_t index, int axis); // axis = 0:rows , axis = 1:cols

MatrixF *remove_matrixf(MatrixF *m, size_t index, int axis); // axis = 0:rows , axis = 1:cols

MatrixD *remove_matrixd(MatrixD *m, size_t index, int axis); // axis = 0:rows , axis = 1:cols

MatrixC *remove_matrixc(MatrixC *m, size_t index, int axis); // axis = 0:rows , axis = 1:cols

#define remove_matrix(m, index, axis) _Generic((m), \
    MatrixI *: remove_matrixi,                      \
    MatrixF *: remove_matrixf,                      \
    MatrixD *: remove_matrixd,                      \
    MatrixC *: remove_matrixc)(m, index, axis)

#endif // REMOVE_LINE_MATRIX_H