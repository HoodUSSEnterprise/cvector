#include "matrix/add_matrix.h"

MatrixI *add_matrixi_i(MatrixI *m1, MatrixI *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixI *res = (MatrixI*)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i];
    }
    return res;
}

MatrixF *add_matrixi_f(MatrixI *m1, MatrixF *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixI *res = (MatrixI*)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i];
    }
    return res;
}

MatrixD *add_matrixi_d(MatrixI *m1, MatrixD *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixI *res = (MatrixI*)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i];
    }
    return res;
}

MatrixC *add_matrixi_c(MatrixI *m1, MatrixC *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixC *res = (MatrixC*)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i].real;
    }
    return res;
}

MatrixF *add_matrixf_i(MatrixF *m1, MatrixI *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixF *res = (MatrixF*)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i];
    }
    return res;
}

MatrixF *add_matrixf_f(MatrixF *m1, MatrixF *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixF *res = (MatrixF*)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i];
    }
    return res;
}

MatrixD *add_matrixf_d(MatrixF *m1, MatrixD *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixD *res = (MatrixD*)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i];
    }
    return res;
}

MatrixC *add_matrixf_c(MatrixF *m1, MatrixC *m2)
{
    // 参数检查
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invaild param!\n");
        return NULL;
    }
    // 维度检查
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
        printf("Dimension mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        return NULL;
    }
    MatrixF *res = (MatrixF*)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->rows = m1->rows;
    res->cols = m1->cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < res->cols * res->rows; i++)
    {
        res->data[i] = m1->data[i] + m2->data[i].real;
    }
    return res;
}

MatrixD *add_matrixd_i(MatrixD *m1, MatrixI *m2);

MatrixD *add_matrixd_f(MatrixD *m1, MatrixF *m2);

MatrixD *add_matrixd_d(MatrixD *m1, MatrixD *m2);

MatrixC *add_matrixd_c(MatrixD *m1, MatrixC *m2);

MatrixC *add_matrixc_i(MatrixC *m1, MatrixI *m2);

MatrixC *add_matrixc_f(MatrixC *m1, MatrixF *m2);

MatrixC *add_matrixc_d(MatrixC *m1, MatrixD *m2);

MatrixC *add_matrixc_c(MatrixC *m1, MatrixC *m2);
