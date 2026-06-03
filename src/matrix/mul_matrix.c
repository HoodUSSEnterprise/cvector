#include "matrix/mul_matrix.h"

MatrixI *mul_matrixi_i(MatrixI *m1, MatrixI *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixI *res = (MatrixI *)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (int *)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(int) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixF *mul_matrixi_f(MatrixI *m1, MatrixF *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(float) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixD *mul_matrixi_d(MatrixI *m1, MatrixD *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixC *mul_matrixi_c(MatrixI *m1, MatrixC *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            Complex sum = {0, 0};
            for (size_t k = 0; k < m1->cols; k++)
            {
                sum = add_complex(sum, mul_complex((Complex){m1->data[i * m1->cols + k], 0}, m2->data[k * m2->cols + j]));
            }
            res->data[i * res->cols + j] = sum;
        }
    }
    return res;
}

MatrixF *mul_matrixf_i(MatrixF *m1, MatrixI *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(float) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixF *mul_matrixf_f(MatrixF *m1, MatrixF *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(float) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixD *mul_matrixf_d(MatrixF *m1, MatrixD *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixC *mul_matrixf_c(MatrixF *m1, MatrixC *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            Complex sum = {0, 0};
            for (size_t k = 0; k < m1->cols; k++)
            {
                sum = add_complex(sum, mul_complex((Complex){m1->data[i * m1->cols + k], 0}, m2->data[k * m2->cols + j]));
            }
            res->data[i * res->cols + j] = sum;
        }
    }
    return res;
}

MatrixD *mul_matrixd_i(MatrixD *m1, MatrixI *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixD *mul_matrixd_f(MatrixD *m1, MatrixF *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixD *mul_matrixd_d(MatrixD *m1, MatrixD *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            for (size_t k = 0; k < m1->cols; k++)
            {
                res->data[i * res->cols + j] += (m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j]);
            }
        }
    }
    return res;
}

MatrixC *mul_matrixd_c(MatrixD *m1, MatrixC *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            Complex sum = {0, 0};
            for (size_t k = 0; k < m1->cols; k++)
            {
                sum = add_complex(sum, mul_complex((Complex){m1->data[i * m1->cols + k], 0}, m2->data[k * m2->cols + j]));
            }
            res->data[i * res->cols + j] = sum;
        }
    }
    return res;
}

MatrixC *mul_matrixc_i(MatrixC *m1, MatrixI *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            Complex sum = {0, 0};
            for (size_t k = 0; k < m1->cols; k++)
            {
                sum = add_complex(sum, mul_complex(m1->data[i * m1->cols + k], (Complex){m2->data[k * m2->cols + j], 0}));
            }
            res->data[i * res->cols + j] = sum;
        }
    }
    return res;
}

MatrixC *mul_matrixc_f(MatrixC *m1, MatrixF *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            Complex sum = {0, 0};
            for (size_t k = 0; k < m1->cols; k++)
            {
                sum = add_complex(sum, mul_complex(m1->data[i * m1->cols + k], (Complex){m2->data[k * m2->cols + j], 0}));
            }
            res->data[i * res->cols + j] = sum;
        }
    }
    return res;
}

MatrixC *mul_matrixc_d(MatrixC *m1, MatrixD *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            Complex sum = {0, 0};
            for (size_t k = 0; k < m1->cols; k++)
            {
                sum = add_complex(sum, mul_complex(m1->data[i * m1->cols + k], (Complex){m2->data[k * m2->cols + j], 0}));
            }
            res->data[i * res->cols + j] = sum;
        }
    }
    return res;
}

MatrixC *mul_matrixc_c(MatrixC *m1, MatrixC *m2)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m1->cols != m2->rows)
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m2->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->rows * res->cols);
    for (size_t i = 0; i < res->rows; i++)
    {
        for (size_t j = 0; j < res->cols; j++)
        {
            Complex sum = {0, 0};
            for (size_t k = 0; k < m1->cols; k++)
            {
                sum = add_complex(sum, mul_complex(m1->data[i * m1->cols + k], m2->data[k * m2->cols + j]));
            }
            res->data[i * res->cols + j] = sum;
        }
    }
    return res;
}
