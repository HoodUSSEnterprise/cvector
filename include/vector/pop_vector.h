#ifndef POP_VECTOR_H
#define POP_VECTOR_H

#include "vector/base_vector.h"

void pop_vectori(Vectori **v, int *elem);

void pop_vectorf(Vectorf **v, float *elem);

void pop_vectord(Vectord **v, double *elem);

void pop_vectorc(Vectorc **v, Complex *elem);

#define pop(v, elem) _Generic((v), \
    Vectori * *: pop_vectori,   \
    Vectorf * *: pop_vectorf,   \
    Vectord * *: pop_vectord,   \
    Vectorc * *: pop_vectorc)(v, elem)

#endif // POP_VECTOR_H