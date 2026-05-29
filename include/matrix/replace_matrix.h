#ifndef REPLACE_MATRIX_H
#define REPLACE_MATRIX_H

#include "matrix/base_matrix.h"
#include "matrix/find_matrix.h"
#include "matrix/copy_matrix.h"
#include "complex/print_complex.h"

MatrixI *replace_matrixi_elem(MatrixI *m, int old_elem, int new_elem);

MatrixF *replace_matrixf_elem(MatrixF *m, float old_elem, float new_elem);

MatrixD *replace_matrixd_elem(MatrixD *m, double old_elem, double new_elem);

MatrixC *replace_matrixc_elem(MatrixC *m, Complex old_elem, Complex new_elem);

#define replace_matrix(m, old_elem, new_elem) _Generic((m), \
    MatrixI *: replace_matrixi_elem,                   \
    MatrixF *: replace_matrixf_elem,                   \
    MatrixD *: replace_matrixd_elem,                   \
    MatrixC *: replace_matrixc_elem)(m, old_elem, new_elem)

#endif // REPLACE_MATRIX_H