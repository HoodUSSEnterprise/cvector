#include "vector/copy_vector.h"

void copy_vectori_i(const Vectori *v1, const Vectori *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (int *)malloc(sizeof(int) * v1->len);
    memcpy(v1->data, v2->data, sizeof(int) * v1->len);
}

void copy_vectorf_f(const Vectorf *v1, const Vectorf *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (float *)malloc(sizeof(float) * v1->len);
    memcpy(v1->data, v2->data, sizeof(float) * v1->len);
}

void copy_vectord_d(const Vectord *v1, const Vectord *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (double *)malloc(sizeof(double) * v1->len);
    memcpy(v1->data, v2->data, sizeof(double) * v1->len);
}

void copy_vectorc_c(const Vectorc *v1, const Vectorc *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (Complex *)malloc(sizeof(Complex) * v1->len);
    memcpy(v1->data, v2->data, sizeof(Complex) * v1->len);
}
