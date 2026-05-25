#ifndef FREE_VECTOR_H
#define FREE_VECTOR_H

#include "vector/base_vector.h"

void free_vector2i(Vector2i *v);

void free_vector2f(Vector2f *v);

void free_vector2d(Vector2d *v);

void free_vector2c(Vector2c *v);

void free_vector3i(Vector3i *v);

void free_vector3f(Vector3f *v);

void free_vector3d(Vector3d *v);

void free_vector3c(Vector3c *v);

void free_vectori(Vectori *v);

void free_vectorf(Vectorf *v);

void free_vectord(Vectord *v);

void free_vectorc(Vectorc *v);

#define free_vec(x) _Generic((x), \
    Vector2c *: free_vector2c,    \
    Vector2d *: free_vector2d,    \
    Vector2f *: free_vector2f,    \
    Vector2i *: free_vector2i,    \
    Vector3c *: free_vector3c,    \
    Vector3d *: free_vector3d,    \
    Vector3f *: free_vector3f,    \
    Vector3i *: free_vector3i,    \
    Vectorc *: free_vectorc,      \
    Vectord *: free_vectord,      \
    Vectorf *: free_vectorf,      \
    Vectori *: free_vectori)(x)

#endif // FREE_VECTOR_H