#ifndef BASE_MATRIX_H
#define BASE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex/base_complex.h"

typedef struct MatrixI
{
    int rows;
    int cols;
    int *data;
}MatrixI;

typedef struct MatrixF
{
    int rows;
    int cols;
    float *data;
}MatrixF;

typedef struct MatrixD
{
    int rows;
    int cols;
    double *data;
}MatrixD;

typedef struct MatrixC
{
    int rows;
    int cols;
    Complex *data;
}MatrixC;


#endif // BASE_MATRIX_H