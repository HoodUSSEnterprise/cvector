#include "matrix/subdeterminant_matrix.h"

// ==================== 余子式（移除指定行和列） ====================

MatrixI *minor_matrixi(MatrixI *m, int row, int col)
{
    if (m == NULL || m->data == NULL || m->rows <= 1 || m->cols <= 1)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (row < 0 || row >= m->rows || col < 0 || col >= m->cols)
    {
        printf("Index out of range! row=%d, col=%d (matrix %dx%d)\n", row, col, m->rows, m->cols);
        return NULL;
    }

    MatrixI *res = (MatrixI *)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (int *)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
            continue;
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
                continue;
            res->data[idx++] = m->data[i * m->cols + j];
        }
    }
    return res;
}

MatrixF *minor_matrixf(MatrixF *m, int row, int col)
{
    if (m == NULL || m->data == NULL || m->rows <= 1 || m->cols <= 1)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (row < 0 || row >= m->rows || col < 0 || col >= m->cols)
    {
        printf("Index out of range! row=%d, col=%d (matrix %dx%d)\n", row, col, m->rows, m->cols);
        return NULL;
    }

    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
            continue;
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
                continue;
            res->data[idx++] = m->data[i * m->cols + j];
        }
    }
    return res;
}

MatrixD *minor_matrixd(MatrixD *m, int row, int col)
{
    if (m == NULL || m->data == NULL || m->rows <= 1 || m->cols <= 1)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (row < 0 || row >= m->rows || col < 0 || col >= m->cols)
    {
        printf("Index out of range! row=%d, col=%d (matrix %dx%d)\n", row, col, m->rows, m->cols);
        return NULL;
    }

    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
            continue;
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
                continue;
            res->data[idx++] = m->data[i * m->cols + j];
        }
    }
    return res;
}

MatrixC *minor_matrixc(MatrixC *m, int row, int col)
{
    if (m == NULL || m->data == NULL || m->rows <= 1 || m->cols <= 1)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (row < 0 || row >= m->rows || col < 0 || col >= m->cols)
    {
        printf("Index out of range! row=%d, col=%d (matrix %dx%d)\n", row, col, m->rows, m->cols);
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
            continue;
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
                continue;
            res->data[idx++] = m->data[i * m->cols + j];
        }
    }
    return res;
}

// ==================== 代数余子式矩阵 ====================

MatrixI *cofactor_matrixi(MatrixI *m)
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
        printf("No memory\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (int *)malloc(sizeof(int) * n * n);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixI *minor = minor_matrixi(m, i, j);
            if (minor == NULL)
            {
                free(res->data);
                free(res);
                return NULL;
            }
            int val = det_matrixi(minor);
            free(minor->data);
            free(minor);
            // 代数余子式：C[i][j] = (-1)^(i+j) * M[i][j]
            if ((i + j) % 2 == 1)
            {
                val = -val;
            }
            res->data[i * n + j] = val;
        }
    }
    return res;
}

MatrixF *cofactor_matrixf(MatrixF *m)
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
        printf("No memory\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (float *)malloc(sizeof(float) * n * n);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixF *minor = minor_matrixf(m, i, j);
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

MatrixD *cofactor_matrixd(MatrixD *m)
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
        printf("No memory\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (double *)malloc(sizeof(double) * n * n);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixD *minor = minor_matrixd(m, i, j);
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

MatrixC *cofactor_matrixc(MatrixC *m)
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
        printf("No memory\n");
        return NULL;
    }
    res->rows = n;
    res->cols = n;
    res->data = (Complex *)malloc(sizeof(Complex) * n * n);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixC *minor = minor_matrixc(m, i, j);
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