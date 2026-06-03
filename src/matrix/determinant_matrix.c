#include "matrix/determinant_matrix.h"
#include <limits.h>
static int Nonei = INT_MAX;
static float Nonef = INT_MAX;
static double Noned = INT_MAX;
static Complex Nonec = (Complex){INT_MAX, INT_MAX};

int det_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return Nonei;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return Nonei;
    }
    int n = m->rows;

    if (n == 1)
    {
        return m->data[0];
    }
    if (n == 2)
    {
        return m->data[0] * m->data[3] - m->data[1] * m->data[2];
    }

    int det = 0;
    for (int j = 0; j < n; j++)
    {
        MatrixI *minor = minor_matrixi(m, 0, j);
        if (minor == NULL)
        {
            return 0;
        }
        int term = m->data[j] * det_matrixi(minor);
        free(minor->data);
        free(minor);
        if (j % 2 == 0)
        {
            det += term;
        }
        else
        {
            det -= term;
        }
    }
    return det;
}

float det_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return Nonef;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return Nonef;
    }
    int n = m->rows;

    if (n == 1)
    {
        return m->data[0];
    }
    if (n == 2)
    {
        return m->data[0] * m->data[3] - m->data[1] * m->data[2];
    }

    float det = 0.0f;
    for (int j = 0; j < n; j++)
    {
        MatrixF *minor = minor_matrixf(m, 0, j);
        if (minor == NULL)
        {
            return 0.0f;
        }
        float term = m->data[j] * det_matrixf(minor);
        free(minor->data);
        free(minor);
        if (j % 2 == 0)
        {
            det += term;
        }
        else
        {
            det -= term;
        }
    }
    return det;
}

double det_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return Noned;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return Noned;
    }
    int n = m->rows;

    if (n == 1)
    {
        return m->data[0];
    }
    if (n == 2)
    {
        return m->data[0] * m->data[3] - m->data[1] * m->data[2];
    }

    double det = 0.0;
    for (int j = 0; j < n; j++)
    {
        MatrixD *minor = minor_matrixd(m, 0, j);
        if (minor == NULL)
        {
            return 0.0;
        }
        double term = m->data[j] * det_matrixd(minor);
        free(minor->data);
        free(minor);
        if (j % 2 == 0)
        {
            det += term;
        }
        else
        {
            det -= term;
        }
    }
    return det;
}

Complex det_matrixc(MatrixC *m)
{
    Complex zero = {0.0, 0.0};
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return Nonec;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square! (%dx%d)\n", m->rows, m->cols);
        return Nonec;
    }
    int n = m->rows;

    if (n == 1)
    {
        return m->data[0];
    }
    if (n == 2)
    {
        return sub_complex(mul_complex(m->data[0], m->data[3]), mul_complex(m->data[1], m->data[2]));
    }

    Complex det = zero;
    for (int j = 0; j < n; j++)
    {
        MatrixC *minor = minor_matrixc(m, 0, j);
        if (minor == NULL)
            return zero;
        Complex term = mul_complex(m->data[j], det_matrixc(minor));
        free(minor->data);
        free(minor);
        if (j % 2 == 0)
        {
            det = add_complex(det, term);
        }
        else
        {
            det = sub_complex(det, term);
        }
    }
    return det;
}

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
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (int *)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
        {
            continue;
        }
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
            {
                continue;
            }
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
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
        {
            continue;
        }
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
            {
                continue;
            }
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
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
        {
            continue;
        }
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
            {
                continue;
            }
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
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m->rows - 1;
    res->cols = m->cols - 1;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < m->rows; i++)
    {
        if (i == row)
        {
            continue;
        }
        for (int j = 0; j < m->cols; j++)
        {
            if (j == col)
            {
                continue;
            }
            res->data[idx++] = m->data[i * m->cols + j];
        }
    }
    return res;
}
