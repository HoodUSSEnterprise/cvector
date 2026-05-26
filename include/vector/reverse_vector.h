#ifndef REVERSE_VECTOR_H
#define REVERSE_VECTOR_H

#include "vector/base_vector.h"

void reverse_vector2i(Vector2i **v);

void reverse_vector2f(Vector2f **v);

void reverse_vector2d(Vector2d **v);

void reverse_vector2c(Vector2c **v);

void reverse_vector3i(Vector3i **v);

void reverse_vector3f(Vector3f **v);

void reverse_vector3d(Vector3d **v);

void reverse_vector3c(Vector3c **v);

void reverse_vectori(Vectori **v);

void reverse_vectorf(Vectorf **v);

void reverse_vectord(Vectord **v);

void reverse_vectorc(Vectorc **v);

#define reverse(x) _Generic((x),    \
    Vector2i * *: reverse_vector2i, \
    Vector2f * *: reverse_vector2f, \
    Vector2d * *: reverse_vector2d, \
    Vector2f * *: reverse_vector2f, \
    Vector3i * *: reverse_vector3i, \
    Vector3f * *: reverse_vector3f, \
    Vector3d * *: reverse_vector3d, \
    Vector3f * *: reverse_vector3f, \
    Vectori * *: reverse_vectori,   \
    Vectorf * *: reverse_vectorf,   \
    Vectord * *: reverse_vectord,   \
    Vectorf * *: reverse_vectorf)(x)

#endif // REVERSE_VECTOR_H