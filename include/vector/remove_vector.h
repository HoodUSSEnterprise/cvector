#ifndef REMOVE_VECTOR_H
#define REMOVE_VECTOR_H

#include "vector/base_vector.h"
#include "complex/operator_complex.h"

Vectori *remove_vectori_elem(const Vectori *v, int elem);

Vectorf *remove_vectorf_elem(const Vectorf *v, float elem);

Vectord *remove_vectord_elem(const Vectord *v, double elem);

Vectorc *remove_vectorc_elem(const Vectorc *v, Complex elem);

Vectori *remove_vectori_array(const Vectori *v, const int *array, size_t len);

Vectorf *remove_vectorf_array(const Vectorf *v, const float *array, size_t len);

Vectord *remove_vectord_array(const Vectord *v, const double *array, size_t len);

Vectorc *remove_vectorc_array(const Vectorc *v, const Complex *array, size_t len);

#define remove_elem(v, elem) _Generic((v), \
    Vectori *: remove_vectori_elem,        \
    Vectorf *: remove_vectorf_elem,        \
    Vectord *: remove_vectord_elem,        \
    Vectorc *: remove_vectorc_elem)(v, elem)

#define remove_arr(v, array, len) _Generic((v), \
    Vectori *: remove_vectori_array,            \
    Vectorf *: remove_vectorf_array,            \
    Vectord *: remove_vectord_array,            \
    Vectorc *: remove_vectorc_array)(v, array, len)

#endif // REMOVE_VECTOR_H