#ifndef RANDOM_TOOL_H
#define RANDOM_TOOL_H

#include "matrix/base_matrix.h"

MatrixD *random_matrixd(int n, int m, double lower, double upper);
MatrixF *random_matrixf(int n, int m, float lower, float upper);

MatrixD *random_col_vectord(int len, double lower, double upper);
MatrixF *random_col_vectorf(int len, float lower, float upper);

MatrixD *random_row_vectord(int len, double lower, double upper);
MatrixF *random_row_vectorf(int len, float lower, float upper);

#endif // RANDOM_TOOL_H
