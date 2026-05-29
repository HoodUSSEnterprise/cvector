#include "matrix/scalar_mul_matrix.h"

// ==================== MatrixI 数乘 ====================

MatrixI *scalar_mul_matrixi_i(MatrixI *m, int s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixI *res = (MatrixI *)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (int *)malloc(sizeof(int) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = m->data[i] * s;
    }
    return res;
}

MatrixF *scalar_mul_matrixi_f(MatrixI *m, float s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (float *)malloc(sizeof(float) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = (float)m->data[i] * s;
    }
    return res;
}

MatrixD *scalar_mul_matrixi_d(MatrixI *m, double s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = (double)m->data[i] * s;
    }
    return res;
}

MatrixC *scalar_mul_matrixi_c(MatrixI *m, Complex s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = mul_complex((Complex){(double)m->data[i], 0.0}, s);
    }
    return res;
}

// ==================== MatrixF 数乘 ====================

MatrixF *scalar_mul_matrixf_i(MatrixF *m, int s)
{
    return scalar_mul_matrixf_f(m, (float)s);
}

MatrixF *scalar_mul_matrixf_f(MatrixF *m, float s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (float *)malloc(sizeof(float) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = m->data[i] * s;
    }
    return res;
}

MatrixD *scalar_mul_matrixf_d(MatrixF *m, double s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = (double)m->data[i] * s;
    }
    return res;
}

MatrixC *scalar_mul_matrixf_c(MatrixF *m, Complex s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = mul_complex((Complex){(double)m->data[i], 0.0}, s);
    }
    return res;
}

// ==================== MatrixD 数乘 ====================

MatrixD *scalar_mul_matrixd_i(MatrixD *m, int s) { return scalar_mul_matrixd_d(m, (double)s); }

MatrixD *scalar_mul_matrixd_f(MatrixD *m, float s) { return scalar_mul_matrixd_d(m, (double)s); }

MatrixD *scalar_mul_matrixd_d(MatrixD *m, double s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = m->data[i] * s;
    }
    return res;
}

MatrixC *scalar_mul_matrixd_c(MatrixD *m, Complex s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
        res->data[i] = mul_complex((Complex){m->data[i], 0.0}, s);
    return res;
}

// ==================== MatrixC 数乘 ====================

MatrixC *scalar_mul_matrixc_i(MatrixC *m, int s)
{
    return scalar_mul_matrixc_c(m, (Complex){(double)s, 0.0});
}

MatrixC *scalar_mul_matrixc_f(MatrixC *m, float s)
{
    return scalar_mul_matrixc_c(m, (Complex){(double)s, 0.0});
}

MatrixC *scalar_mul_matrixc_d(MatrixC *m, double s)
{
    return scalar_mul_matrixc_c(m, (Complex){s, 0.0});
}

MatrixC *scalar_mul_matrixc_c(MatrixC *m, Complex s)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m->rows;
    res->cols = m->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * m->rows * m->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        res->data[i] = mul_complex(m->data[i], s);
    }
    return res;
}
