#include "matrix/extract_matrix.h"
#include <limits.h>

// ==================== 提取列向量 ====================

MatrixI *col_vector_matrixi(MatrixI *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (index < 0 || index >= m->cols)
    {
        printf("Index out of range!\n");
        return NULL;
    }
    MatrixI *res = (MatrixI *)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = 1;
    res->data = (int *)malloc(sizeof(int) * m->rows);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows; i++)
    {
        res->data[i] = m->data[i * m->cols + index];
    }
    return res;
}

MatrixF *col_vector_matrixf(MatrixF *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (index < 0 || index >= m->cols)
    {
        printf("Index out of range!\n");
        return NULL;
    }
    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = 1;
    res->data = (float *)malloc(sizeof(float) * m->rows);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows; i++)
    {
        res->data[i] = m->data[i * m->cols + index];
    }
    return res;
}

MatrixD *col_vector_matrixd(MatrixD *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (index < 0 || index >= m->cols)
    {
        printf("Index out of range!\n");
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = 1;
    res->data = (double *)malloc(sizeof(double) * m->rows);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows; i++)
    {
        res->data[i] = m->data[i * m->cols + index];
    }
    return res;
}

MatrixC *col_vector_matrixc(MatrixC *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (index < 0 || index >= m->cols)
    {
        printf("Index out of range!\n");
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = 1;
    res->data = (Complex *)malloc(sizeof(Complex) * m->rows);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows; i++)
    {
        res->data[i] = m->data[i * m->cols + index];
    }
    return res;
}

// ==================== 获取对角线元素 ====================

int *get_diag_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    int n = m->rows < m->cols ? m->rows : m->cols;
    int *res = (int *)malloc(sizeof(int) * n);
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = m->data[i * m->cols + i];
    }
    return res;
}

float *get_diag_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    int n = m->rows < m->cols ? m->rows : m->cols;
    float *res = (float *)malloc(sizeof(float) * n);
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = m->data[i * m->cols + i];
    }
    return res;
}

double *get_diag_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    int n = m->rows < m->cols ? m->rows : m->cols;
    double *res = (double *)malloc(sizeof(double) * n);
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = m->data[i * m->cols + i];
    }
    return res;
}

Complex *get_diag_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    int n = m->rows < m->cols ? m->rows : m->cols;
    Complex *res = (Complex *)malloc(sizeof(Complex) * n);
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = m->data[i * m->cols + i];
    }
    return res;
}
