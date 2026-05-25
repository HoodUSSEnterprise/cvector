#include "vector/copy_vector.h"

void copy_vectori_i(Vectori *v1, Vectori *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (int *)malloc(sizeof(int) * v1->len);
    memcpy(v1->data, v2->data, sizeof(int) * v1->len);
}

void copy_vectorf_f(Vectorf *v1, Vectorf *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (float *)malloc(sizeof(float) * v1->len);
    memcpy(v1->data, v2->data, sizeof(float) * v1->len);
}

void copy_vectord_d(Vectord *v1, Vectord *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (double *)malloc(sizeof(double) * v1->len);
    memcpy(v1->data, v2->data, sizeof(double) * v1->len);
}

void copy_vectorc_c(Vectorc *v1, Vectorc *v2)
{
    v1->len = v2->len;
    free(v1->data);
    v1->data = (Complex *)malloc(sizeof(Complex) * v1->len);
    memcpy(v1->data, v2->data, sizeof(Complex) * v1->len);
}
