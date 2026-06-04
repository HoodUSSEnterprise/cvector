#ifndef REPLACE_VECTOR_H
#define REPLACE_VECTOR_H

#include "vector/base_vector.h"
#include "vector/find_vector.h"
#include "vector/create_vector.h"
#include "complex/print_complex.h"
#include <math.h>

Vector2i *replace_vector2i_elem(Vector2i *v, int old_elem, int new_elem);

Vector2f *replace_vector2f_elem(Vector2f *v, float old_elem, float new_elem);

Vector2d *replace_vector2d_elem(Vector2d *v, double old_elem, double new_elem);

Vector2c *replace_vector2c_elem(Vector2c *v, Complex old_elem, Complex new_elem);

Vector3i *replace_vector3i_elem(Vector3i *v, int old_elem, int new_elem);

Vector3f *replace_vector3f_elem(Vector3f *v, float old_elem, float new_elem);

Vector3d *replace_vector3d_elem(Vector3d *v, double old_elem, double new_elem);

Vector3c *replace_vector3c_elem(Vector3c *v, Complex old_elem, Complex new_elem);

Vectori *replace_vectori_elem(Vectori *v, int old_elem, int new_elem);

Vectorf *replace_vectorf_elem(Vectorf *v, float old_elem, float new_elem);

Vectord *replace_vectord_elem(Vectord *v, double old_elem, double new_elem);

Vectorc *replace_vectorc_elem(Vectorc *v, Complex old_elem, Complex new_elem);

Vectori *replace_vectori_array(Vectori *v, const int *old_array, const int *new_array, size_t len);

Vectorf *replace_vectorf_array(Vectorf *v, const float *old_array, const float *new_array, size_t len);

Vectord *replace_vectord_array(Vectord *v, const double *old_array, const double *new_array, size_t len);

Vectorc *replace_vectorc_array(Vectorc *v, const Complex *old_array, const Complex *new_array, size_t len);

#define replace_elem(x, y, z) _Generic((x), \
    Vector2i *: replace_vector2i_elem,      \
    Vector2f *: replace_vector2f_elem,      \
    Vector2d *: replace_vector2d_elem,      \
    Vector2c *: replace_vector2c_elem,      \
    Vector3i *: replace_vector3i_elem,      \
    Vector3f *: replace_vector3f_elem,      \
    Vector3d *: replace_vector3d_elem,      \
    Vector3c *: replace_vector3c_elem,      \
    Vectori *: replace_vectori_elem,        \
    Vectorf *: replace_vectorf_elem,        \
    Vectord *: replace_vectord_elem,        \
    Vectorc *: replace_vectorc_elem)(x, y, z)

#define replace_arr(x, y, z, a) _Generic((x), \
    Vectori *: replace_vectori_array,         \
    Vectorf *: replace_vectorf_array,         \
    Vectord *: replace_vectord_array,         \
    Vectorc *: replace_vectorc_array)(x, y, z, a)

#endif // REPLACE_VECTOR_H