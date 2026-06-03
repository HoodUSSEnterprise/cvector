#include "matrix/random_tool.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 简单线性同余随机数生成器（避免链接 -lm 问题）
static double rand_uniform(double lower, double upper)
{
    return lower + (upper - lower) * ((double)rand() / (RAND_MAX + 1.0));
}

// ==================== 随机矩阵 ====================

MatrixD *random_matrixd(int n, int m, double lower, double upper)
{
    if (n <= 0 || m <= 0)
    {
        printf("Invalid size!\n");
        return NULL;
    }
    srand((unsigned int)time(NULL));
    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = n;
    res->cols = m;
    res->data = (double *)malloc(sizeof(double) * n * m);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < n * m; i++)
    {
        res->data[i] = rand_uniform(lower, upper);
    }
    return res;
}

MatrixF *random_matrixf(int n, int m, float lower, float upper)
{
    if (n <= 0 || m <= 0)
    {
        printf("Invalid size!\n");
        return NULL;
    }
    srand((unsigned int)time(NULL));
    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = n;
    res->cols = m;
    res->data = (float *)malloc(sizeof(float) * n * m);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (int i = 0; i < n * m; i++)
    {
        res->data[i] = (float)rand_uniform((double)lower, (double)upper);
    }
    return res;
}

// ==================== 随机列向量 ====================

MatrixD *random_col_vectord(int len, double lower, double upper)
{
    return random_matrixd(len, 1, lower, upper);
}

MatrixF *random_col_vectorf(int len, float lower, float upper)
{
    return random_matrixf(len, 1, lower, upper);
}

// ==================== 随机行向量 ====================

MatrixD *random_row_vectord(int len, double lower, double upper)
{
    return random_matrixd(1, len, lower, upper);
}

MatrixF *random_row_vectorf(int len, float lower, float upper)
{
    return random_matrixf(1, len, lower, upper);
}
