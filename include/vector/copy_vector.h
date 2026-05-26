#ifndef COPY_VECTOR_H
#define COPY_VECTOR_H

#include "vector/base_vector.h"

void copy_vectori_i(const Vectori *v1, const Vectori *v2);

void copy_vectorf_f(const Vectorf *v1, const Vectorf *v2);

void copy_vectord_d(const Vectord *v1, const Vectord *v2);

void copy_vectorc_c(const Vectorc *v1, const Vectorc *v2);

#define copy_vec(x, y) _Generic((x), \
    Vectori *: copy_vectori_i,       \
    Vectorf *: copy_vectorf_f,       \
    Vectord *: copy_vectord_d,       \
    Vectorc *: copy_vectorc_c)(x, y)

#endif // COPY_VECTOR_H