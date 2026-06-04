#include "vector/pop_vector.h"

void pop_vectori(Vectori **v, int *elem)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    if ((*v)->len == 0)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len - 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    *elem = (*v)->data[res->len];
    free((*v)->data);
    free((*v));
    *v = res;
}

void pop_vectorf(Vectorf **v, float *elem)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    if ((*v)->len == 0)
    {
        return;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len - 1;
    res->data = (float *)malloc(sizeof(float) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    *elem = (*v)->data[res->len];
    free((*v)->data);
    free((*v));
    *v = res;
}

void pop_vectord(Vectord **v, double *elem)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    if ((*v)->len == 0)
    {
        return;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len - 1;
    res->data = (double *)malloc(sizeof(double) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    *elem = (*v)->data[res->len];
    free((*v)->data);
    free((*v));
    *v = res;
}

void pop_vectorc(Vectorc **v, Complex *elem)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    if ((*v)->len == 0)
    {
        return;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    res->len = (*v)->len - 1;
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    *elem = (*v)->data[res->len];
    free((*v)->data);
    free((*v));
    *v = res;
}