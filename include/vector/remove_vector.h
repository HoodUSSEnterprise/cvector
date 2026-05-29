#ifndef REMOVE_VECTOR_H
#define REMOVE_VECTOR_H

#include "vector/base_vector.h"
#include "complex/operator_complex.h"

Vectori *remove_vectori_elem(Vectori *v, int elem);

Vectorf *remove_vectorf_elem(Vectorf *v, float elem);

Vectord *remove_vectord_elem(Vectord *v, double elem);

Vectorc *remove_vectorc_elem(Vectorc *v, Complex elem);

Vectori *remove_vectori_array(Vectori *v, int *array, size_t len);

Vectorf *remove_vectorf_array(Vectorf *v, float *array, size_t len);

Vectord *remove_vectord_array(Vectord *v, double *array, size_t len);

Vectorc *remove_vectorc_array(Vectorc *v, Complex *array, size_t len);

#define remove_elem(v, elem) _Generic((v), \
    Vectori *: remove_vectori_elem,     \
    Vectorf *: remove_vectorf_elem,     \
    Vectord *: remove_vectord_elem,     \
    Vectorc *: remove_vectorc_elem)(v, elem)

#define remove_arr(v, array, len) _Generic((v), \
    Vectori *: remove_vectori_array,      \
    Vectorf *: remove_vectorf_array,      \
    Vectord *: remove_vectord_array,      \
    Vectorc *: remove_vectorc_array)(v, array, len)

#endif // REMOVE_VECTOR_H