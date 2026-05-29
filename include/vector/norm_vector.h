#ifndef NORM_VECTOR_H
#define NORM_VECTOR_H

#include "vector/base_vector.h"
#include "complex/operator_complex.h"
#include <math.h>

extern double None;

double norm_vector2i(Vector2i *v, double norm);

double norm_vector2f(Vector2f *v, double norm);

double norm_vector2d(Vector2d *v, double norm);

double norm_vector2c(Vector2c *v, double norm);

double norm_vector3i(Vector3i *v, double norm);

double norm_vector3f(Vector3f *v, double norm);

double norm_vector3d(Vector3d *v, double norm);

double norm_vector3c(Vector3c *v, double norm);

double norm_vectori(Vectori *v, double norm);

double norm_vectorf(Vectorf *v, double norm);

double norm_vectord(Vectord *v, double norm);

double norm_vectorc(Vectorc *v, double norm);

#define norm_vec(v, norm) _Generic((v), \
    Vector2c *: norm_vector2c,       \
    Vector2d *: norm_vector2d,       \
    Vector2f *: norm_vector2f,       \
    Vector2i *: norm_vector2i,       \
    Vector3c *: norm_vector3c,       \
    Vector3d *: norm_vector3d,       \
    Vector3f *: norm_vector3f,       \
    Vector3i *: norm_vector3i,       \
    Vectorc *: norm_vectorc,         \
    Vectord *: norm_vectord,         \
    Vectorf *: norm_vectorf,         \
    Vectori *: norm_vectori)(v, norm)

#endif // NORM_VECTOR_H