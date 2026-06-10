#ifndef CREATE_VECTOR_H
#define CREATE_VECTOR_H

#include "complex/operator_complex.h"
#include "vector/base_vector.h"

Vector2i *create_vector2i(int x, int y);

Vector2f *create_vector2f(float x, float y);

Vector2d *create_vector2d(double x, double y);

Vector2c *create_vector2c(Complex x, Complex y);

Vector3i *create_vector3i(int x, int y, int z);

Vector3f *create_vector3f(float x, float y, float z);

Vector3d *create_vector3d(double x, double y, double z);

Vector3c *create_vector3c(Complex x, Complex y, Complex z);

Vectori *create_vectori(int *data, size_t len);

Vectorf *create_vectorf(float *data, size_t len);

Vectord *create_vectord(double *data, size_t len);

Vectorc *create_vectorc(Complex *data, size_t len);

#define create_vec2(x, y) _Generic((x), \
    Complex: create_vector2c,           \
    double: _Generic((y),               \
        Complex: create_vector2c,       \
        double: create_vector2d,        \
        float: create_vector2f,         \
        int: create_vector2i),          \
    float: _Generic((y),                \
        Complex: create_vector2c,       \
        double: create_vector2d,        \
        float: create_vector2f,         \
        int: create_vector2f),          \
    int: _Generic((y),                  \
        Complex: create_vector2c,       \
        double: create_vector2d,        \
        float: create_vector2f,         \
        int: create_vector2i))(x, y)

#define create_vec3(x, y, z) _Generic((x), \
    Complex: create_vector3c,              \
    double: _Generic((y),                  \
        Complex: create_vector3c,          \
        double: _Generic((z),              \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3d,        \
            int: create_vector3d),         \
        float: _Generic((z),               \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3d,        \
            int: create_vector3d),         \
        int: _Generic((z),                 \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3d,        \
            int: create_vector3d), ),      \
    float: _Generic((y),                   \
        Complex: create_vector3c,          \
        double: _Generic((z),              \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3d,        \
            int: create_vector3d),         \
        float: _Generic((z),               \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3f,        \
            int: create_vector3f),         \
        int: _Generic((z),                 \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3f,        \
            int: create_vector3f), ),      \
    int: _Generic((y),                     \
        Complex: create_vector3c,          \
        double: _Generic((z),              \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3d,        \
            int: create_vector3d),         \
        float: _Generic((z),               \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3f,        \
            int: create_vector3f),         \
        int: _Generic((z),                 \
            Complex: create_vector3c,      \
            double: create_vector3d,       \
            float: create_vector3f,        \
            int: create_vector3i), ))(x, y, z)

#define create_vec(y, len) _Generic((y), \
    int *: create_vectori,               \
    float *: create_vectorf,             \
    double *: create_vectord,            \
    Complex *: create_vectorc)(y, len)

#endif // CREATE_VECTOR_H