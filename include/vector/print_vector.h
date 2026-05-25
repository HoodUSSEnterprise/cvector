#ifndef PRINT_VECTOR_H
#define PRINT_VECTOR_H

#include "vector/base_vector.h"

void print_vector2i(Vector2i *v);

void print_vector2f(Vector2f *v);

void print_vector2d(Vector2d *v);

void print_vector2c(Vector2c *v);

void print_vector3i(Vector3i *v);

void print_vector3f(Vector3f *v);

void print_vector3d(Vector3d *v);

void print_vector3c(Vector3c *v);

void print_vectori(Vectori *v);

void print_vectorf(Vectorf *v);

void print_vectord(Vectord *v);

void print_vectorc(Vectorc *v);

#define print_vec(v) _Generic((v), \
    Vector2i *: print_vector2i,    \
    Vector2f *: print_vector2f,    \
    Vector2d *: print_vector2d,    \
    Vector2c *: print_vector2c,    \
    Vector3i *: print_vector3i,    \
    Vector3f *: print_vector3f,    \
    Vector3d *: print_vector3d,    \
    Vector3c *: print_vector3c,    \
    Vectori *: print_vectori,      \
    Vectorf *: print_vectorf,      \
    Vectord *: print_vectord,      \
    Vectorc *: print_vectorc)(v)

#endif // PRINT_VECTOR_H