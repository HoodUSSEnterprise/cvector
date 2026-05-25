#ifndef FIND_VECTOR_H
#define FIND_VECTOR_H

#include "vector/base_vector.h"
#include "complex/operator_complex.h"
#include <math.h>

int find_vector2i(Vector2i *v, int elem);

int find_vector2f(Vector2f *v, float elem);

int find_vector2d(Vector2d *v, double elem);

int find_vector2c(Vector2c *v, Complex elem);

int find_vector3i(Vector3i *v, int elem);

int find_vector3f(Vector3f *v, float elem);

int find_vector3d(Vector3d *v, double elem);

int find_vector3c(Vector3c *v, Complex elem);

int find_vectori(Vectori *v, int elem);

int find_vectorf(Vectorf *v, float elem);

int find_vectord(Vectord *v, double elem);

int find_vectorc(Vectorc *v, Complex elem);

#define find_elem(x, y) _Generic((x), \
    Vector2c *: find_vector2c,        \
    Vector2d *: find_vector2d,        \
    Vector2f *: find_vector2f,        \
    Vector2i *: find_vector2i,        \
    Vector3c *: find_vector3c,        \
    Vector3d *: find_vector3d,        \
    Vector3f *: find_vector3f,        \
    Vector3i *: find_vector3i,        \
    Vectorc *: find_vectorc,          \
    Vectord *: find_vectord,          \
    Vectorf *: find_vectorf,          \
    Vectori *: find_vectori)(x, y)

#endif // FIND_VECTOR_H