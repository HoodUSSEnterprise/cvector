#include "matrix/adjugate_matrix.h"

MatrixI *adjugate_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return NULL;
    }
    int n = m->rows;

    MatrixI *res = (MatrixI *)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (int *)malloc(sizeof(int) * n * n);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // adj(A)[i][j] = (-1)^(i+j) * det(minor(A, j, i))
            MatrixI *minor = minor_matrixi(m, j, i);
            if (minor == NULL)
            {
                free(res->data);
                free(res);
                return NULL;
            }
            int val = det_matrixi(minor);
            free(minor->data);
            free(minor);
            if ((i + j) % 2 == 1)
            {
                val = -val;
            }
            res->data[i * n + j] = val;
        }
    }
    return res;
}

MatrixF *adjugate_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return NULL;
    }
    int n = m->rows;

    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (float *)malloc(sizeof(float) * n * n);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixF *minor = minor_matrixf(m, j, i);
            if (minor == NULL)
            {
                free(res->data);
                free(res);
                return NULL;
            }
            float val = det_matrixf(minor);
            free(minor->data);
            free(minor);
            if ((i + j) % 2 == 1)
            {
                val = -val;
            }
            res->data[i * n + j] = val;
        }
    }
    return res;
}

MatrixD *adjugate_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return NULL;
    }
    int n = m->rows;

    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (double *)malloc(sizeof(double) * n * n);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixD *minor = minor_matrixd(m, j, i);
            if (minor == NULL)
            {
                free(res->data);
                free(res);
                return NULL;
            }
            double val = det_matrixd(minor);
            free(minor->data);
            free(minor);
            if ((i + j) % 2 == 1)
            {
                val = -val;
            }
            res->data[i * n + j] = val;
        }
    }
    return res;
}

MatrixC *adjugate_matrixc(MatrixC *m)
{
    Complex zero = {0.0, 0.0};
    Complex minus_one = {-1.0, 0.0};

    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return NULL;
    }
    int n = m->rows;

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (Complex *)malloc(sizeof(Complex) * n * n);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixC *minor = minor_matrixc(m, j, i);
            if (minor == NULL)
            {
                free(res->data);
                free(res);
                return NULL;
            }
            Complex val = det_matrixc(minor);
            free(minor->data);
            free(minor);
            if ((i + j) % 2 == 1)
            {
                val = mul_complex(minus_one, val);
            }
            res->data[i * n + j] = val;
        }
    }
    return res;
}
