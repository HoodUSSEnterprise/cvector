#ifndef INSERT_VECTOR_H
#define INSERT_VECTOR_H

#include "vector/base_vector.h"

void insert_vectori_i(Vectori **v, size_t pos, int value);

void insert_vectori_f(Vectori **v, size_t pos, float value);

void insert_vectori_d(Vectori **v, size_t pos, double value);

void insert_vectori_c(Vectori **v, size_t pos, Complex value);

void insert_vectorf_i(Vectorf **v, size_t pos, int value);

void insert_vectorf_f(Vectorf **v, size_t pos, float value);

void insert_vectorf_d(Vectorf **v, size_t pos, double value);

void insert_vectorf_c(Vectorf **v, size_t pos, Complex value);

void insert_vectord_i(Vectord **v, size_t pos, int value);

void insert_vectord_f(Vectord **v, size_t pos, float value);

void insert_vectord_d(Vectord **v, size_t pos, double value);

void insert_vectord_c(Vectord **v, size_t pos, Complex value);

void insert_vectorc_i(Vectorc **v, size_t pos, int value);

void insert_vectorc_f(Vectorc **v, size_t pos, float value);

void insert_vectorc_d(Vectorc **v, size_t pos, double value);

void insert_vectorc_c(Vectorc **v, size_t pos, Complex value);

#define insert(v, pos, value) _Generic((v),   \
    Vectori * *: _Generic((value),          \
            int: insert_vectori_i,      \
            float: insert_vectori_f,    \
            double: insert_vectori_d,   \
            Complex: insert_vectori_c), \
    Vectorf * *: _Generic((value),          \
            int: insert_vectorf_i,      \
            float: insert_vectorf_f,    \
            double: insert_vectorf_d,   \
            Complex: insert_vectorf_c), \
    Vectord * *: _Generic((value),          \
            int: insert_vectord_i,      \
            float: insert_vectord_f,    \
            double: insert_vectord_d,   \
            Complex: insert_vectord_c), \
    Vectorc * *: _Generic((value),          \
            int: insert_vectorc_i,      \
            float: insert_vectorc_f,    \
            double: insert_vectorc_d,   \
            Complex: insert_vectorc_c))(v, pos, value)

#endif // INSERT_VECTOR_H