#include "matrix/sub_matrix.h"

MatrixI *sub_matrixi_i(MatrixI *m1, MatrixI *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (int *)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixF *sub_matrixi_f(MatrixI *m1, MatrixF *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixD *sub_matrixi_d(MatrixI *m1, MatrixD *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixC *sub_matrixi_c(MatrixI *m1, MatrixC *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = sub_complex((Complex){m1->data[i], 0}, m2->data[i]);
    }
    return res;
}

MatrixF *sub_matrixf_i(MatrixF *m1, MatrixI *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixF *sub_matrixf_f(MatrixF *m1, MatrixF *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixD *sub_matrixf_d(MatrixF *m1, MatrixD *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixC *sub_matrixf_c(MatrixF *m1, MatrixC *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = sub_complex((Complex){m1->data[i], 0}, m2->data[i]);
    }
    return res;
}

MatrixD *sub_matrixd_i(MatrixD *m1, MatrixI *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixD *sub_matrixd_f(MatrixD *m1, MatrixF *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixD *sub_matrixd_d(MatrixD *m1, MatrixD *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] - m2->data[i];
    }
    return res;
}

MatrixC *sub_matrixd_c(MatrixD *m1, MatrixC *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = sub_complex((Complex){m1->data[i], 0}, m2->data[i]);
    }
    return res;
}

MatrixC *sub_matrixc_i(MatrixC *m1, MatrixI *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = sub_complex(m1->data[i], (Complex){m2->data[i], 0});
    }
    return res;
}

MatrixC *sub_matrixc_f(MatrixC *m1, MatrixF *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = sub_complex(m1->data[i], (Complex){m2->data[i], 0});
    }
    return res;
}

MatrixC *sub_matrixc_d(MatrixC *m1, MatrixD *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = sub_complex(m1->data[i], (Complex){m2->data[i], 0});
    }
    return res;
}

MatrixC *sub_matrixc_c(MatrixC *m1, MatrixC *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
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
    res->cols = m1->cols;
    res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = sub_complex(m1->data[i], m2->data[i]);
    }
    return res;
}
