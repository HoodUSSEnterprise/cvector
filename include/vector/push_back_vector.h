#ifndef PUSH_BACK_VECTOR_H
#define PUSH_BACK_VECTOR_H

#include "vector/base_vector.h"

void push_back_vectori_i(Vectori **v, int push_number);

void push_back_vectori_f(Vectori **v, float push_number);

void push_back_vectori_d(Vectori **v, double push_number);

void push_back_vectori_c(Vectori **v, Complex push_number);

void push_back_vectorf_i(Vectorf **v, int push_number);

void push_back_vectorf_f(Vectorf **v, float push_number);

void push_back_vectorf_d(Vectorf **v, double push_number);

void push_back_vectorf_c(Vectorf **v, Complex push_number);

void push_back_vectord_i(Vectord **v, int push_number);

void push_back_vectord_f(Vectord **v, float push_number);

void push_back_vectord_d(Vectord **v, double push_number);

void push_back_vectord_c(Vectord **v, Complex push_number);

void push_back_vectorc_i(Vectorc **v, int push_number);

void push_back_vectorc_f(Vectorc **v, float push_number);

void push_back_vectorc_d(Vectorc **v, double push_number);

void push_back_vectorc_c(Vectorc **v, Complex push_number);

#define push_back(x, y) _Generic((x),      \
    Vectori * *: _Generic((y),             \
            int: push_back_vectori_i,      \
            float: push_back_vectori_f,    \
            double: push_back_vectori_d,   \
            Complex: push_back_vectori_c), \
    Vectorf * *: _Generic((y),             \
            int: push_back_vectorf_i,      \
            float: push_back_vectorf_f,    \
            double: push_back_vectorf_d,   \
            Complex: push_back_vectorf_c), \
    Vectord * *: _Generic((y),             \
            int: push_back_vectord_i,      \
            float: push_back_vectord_f,    \
            double: push_back_vectord_d,   \
            Complex: push_back_vectord_c), \
    Vectorc * *: _Generic((y),             \
            int: push_back_vectorc_i,      \
            float: push_back_vectorc_f,    \
            double: push_back_vectorc_d,   \
            Complex: push_back_vectorc_c))(x, y)

#endif // PUSH_BACK_VECTOR_H