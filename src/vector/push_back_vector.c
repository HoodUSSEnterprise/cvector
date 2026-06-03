#include "vector/push_back_vector.h"

void push_back_vectori_i(Vectori **v, int push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectori_f(Vectori **v, float push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (int)push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectori_d(Vectori **v, double push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (int)push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectori_c(Vectori **v, Complex push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (int)push_number.real;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorf_i(Vectorf **v, int push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (float *)malloc(sizeof(float) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (float)push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorf_f(Vectorf **v, float push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (float *)malloc(sizeof(float) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorf_d(Vectorf **v, double push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (float *)malloc(sizeof(float) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (float)push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorf_c(Vectorf **v, Complex push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (float *)malloc(sizeof(float) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (float)push_number.real;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectord_i(Vectord **v, int push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (double *)malloc(sizeof(double) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (double)push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectord_f(Vectord **v, float push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (double *)malloc(sizeof(double) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (double)push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectord_d(Vectord **v, double push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (double *)malloc(sizeof(double) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (double)push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectord_c(Vectord **v, Complex push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (double *)malloc(sizeof(double) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (double)push_number.real;
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorc_i(Vectorc **v, int push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (Complex){push_number, 0};
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorc_f(Vectorc **v, float push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (Complex){push_number, 0};
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorc_d(Vectorc **v, double push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = (Complex){push_number, 0};
    free((*v)->data);
    free((*v));
    *v = res;
}

void push_back_vectorc_c(Vectorc **v, Complex push_number)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len + 1;
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}