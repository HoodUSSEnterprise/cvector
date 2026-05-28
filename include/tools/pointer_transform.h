#ifndef POINTER_TRANSFORM_H
#define POINTER_TRANSFORM_H

#include <stdio.h>
#include "complex/base_complex.h"

int *transfrom_pointerf2i(float *data, size_t len);

int *transfrom_pointerd2i(double *data, size_t len);

int *transfrom_pointerc2i(Complex *data, size_t len);

float *transfrom_pointeri2f(int *data, size_t len);

float *transfrom_pointerd2f(double *data, size_t len);

float *transfrom_pointerc2f(Complex *data, size_t len);

double *transfrom_pointeri2d(int *data, size_t len);

double *transfrom_pointerf2d(float *data, size_t len);

double *transfrom_pointerc2d(Complex *data, size_t len);

Complex *transfrom_pointeri2c(int *data, size_t len);

Complex *transfrom_pointerf2c(float *data, size_t len);

Complex *transfrom_pointerd2c(double *data, size_t len);

#endif // POINTER_TRANSFORM_H