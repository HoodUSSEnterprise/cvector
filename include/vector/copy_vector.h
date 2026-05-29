#ifndef COPY_VECTOR_H
#define COPY_VECTOR_H

#include "vector/base_vector.h"

void copy_vectori_i(Vectori *v1, Vectori *v2);

void copy_vectorf_f(Vectorf *v1, Vectorf *v2);

void copy_vectord_d(Vectord *v1, Vectord *v2);

void copy_vectorc_c(Vectorc *v1, Vectorc *v2);

#define copy_vec(x, y) _Generic((x), \
    Vectori *: copy_vectori_i,       \
    Vectorf *: copy_vectorf_f,       \
    Vectord *: copy_vectord_d,       \
    Vectorc *: copy_vectorc_c)(x, y)

#endif // COPY_VECTOR_H