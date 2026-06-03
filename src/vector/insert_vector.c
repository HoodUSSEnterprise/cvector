#include "vector/insert_vector.h"

void insert_vectori_i(Vectori **v, size_t pos, int value)
{
    if (v == NULL || (*v) == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    if (pos > (*v)->len - 1) // 默认pos大于数组长度，直接插入到最后
    {
        memcpy(res->data, (*v)->data, sizeof(int) * (*v)->len);
        res->data[(res->len) - 1] = value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len, j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = value;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectori_f(Vectori **v, size_t pos, float value)
{
    if (v == NULL || (*v) == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    if (pos > (*v)->len - 1) // 默认pos大于数组长度，直接插入到最后
    {
        memcpy(res->data, (*v)->data, sizeof(int) * (*v)->len);
        res->data[(res->len) - 1] = (int)value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len, j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (int)value;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectori_d(Vectori **v, size_t pos, double value)
{
    if (v == NULL || (*v) == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    if (pos > (*v)->len - 1) // 默认pos大于数组长度，直接插入到最后
    {
        memcpy(res->data, (*v)->data, sizeof(int) * (*v)->len);
        res->data[(res->len) - 1] = (int)value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len, j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (int)value;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectori_c(Vectori **v, size_t pos, Complex value)
{
    if (v == NULL || (*v) == NULL)
    {
        return;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    res->len = (*v)->len + 1;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    if (pos > (*v)->len - 1) // 默认pos大于数组长度，直接插入到最后
    {
        memcpy(res->data, (*v)->data, sizeof(int) * (*v)->len);
        res->data[(res->len) - 1] = (int)value.real;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len, j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (int)value.real;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorf_i(Vectorf **v, size_t pos, int value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(float) * (*v)->len);
        res->data[(res->len) - 1] = (float)value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (float)value;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorf_f(Vectorf **v, size_t pos, float value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(float) * (*v)->len);
        res->data[(res->len) - 1] = value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = value;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorf_d(Vectorf **v, size_t pos, double value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(float) * (*v)->len);
        res->data[(res->len) - 1] = (float)value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (float)value;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorf_c(Vectorf **v, size_t pos, Complex value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(float) * (*v)->len);
        res->data[(res->len) - 1] = (float)value.real;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (float)value.real;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectord_i(Vectord **v, size_t pos, int value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(double) * (*v)->len);
        res->data[(res->len) - 1] = (double)value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (double)value;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectord_f(Vectord **v, size_t pos, float value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(double) * (*v)->len);
        res->data[(res->len) - 1] = (double)value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (double)value;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectord_d(Vectord **v, size_t pos, double value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(double) * (*v)->len);
        res->data[(res->len) - 1] = value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = value;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectord_c(Vectord **v, size_t pos, Complex value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(double) * (*v)->len);
        res->data[(res->len) - 1] = (double)value.real;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = (double)value.real;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorc_i(Vectorc **v, size_t pos, int value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(Complex) * (*v)->len);
        res->data[(res->len) - 1].real = (double)value;
        res->data[(res->len) - 1].imag = 0.0;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i].real = (double)value;
                res->data[i].imag = 0.0;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorc_f(Vectorc **v, size_t pos, float value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(Complex) * (*v)->len);
        res->data[(res->len) - 1].real = (double)value;
        res->data[(res->len) - 1].imag = 0.0;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i].real = (double)value;
                res->data[i].imag = 0.0;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorc_d(Vectorc **v, size_t pos, double value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(Complex) * (*v)->len);
        res->data[(res->len) - 1].real = value;
        res->data[(res->len) - 1].imag = 0.0;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i].real = value;
                res->data[i].imag = 0.0;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void insert_vectorc_c(Vectorc **v, size_t pos, Complex value)
{
    if (v == NULL || (*v) == NULL)
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
        free(res);
        return;
    }
    if (pos > (*v)->len - 1)
    {
        memcpy(res->data, (*v)->data, sizeof(Complex) * (*v)->len);
        res->data[(res->len) - 1] = value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len && j < (*v)->len; i++, j++)
        {
            if (i == pos)
            {
                res->data[i] = value;
                j--;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}