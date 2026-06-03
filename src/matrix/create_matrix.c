#include "matrix/create_matrix.h"
#include "tools/pointer_transform.h"

MatrixI *create_matrixi_i(int rows, int cols, int *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    MatrixI *res = (MatrixI*)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(int) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = data[i];
        }
    }
    return res;
}

MatrixI *create_matrixi_f(int rows, int cols, float *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    int *new_data = transfrom_pointerf2i(data, len);
    MatrixI *res = (MatrixI*)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(int) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixI *create_matrixi_d(int rows, int cols, double *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    int *new_data = transfrom_pointerd2i(data, len);
    MatrixI *res = (MatrixI*)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(int) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixI *create_matrixi_c(int rows, int cols, Complex *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    int *new_data = transfrom_pointerc2i(data, len);
    MatrixI *res = (MatrixI*)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (int*)malloc(sizeof(int) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(int) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixF *create_matrixf_i(int rows, int cols, int *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    float *new_data = transfrom_pointeri2f(data, len);
    MatrixF *res = (MatrixF*)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(float) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixF *create_matrixf_f(int rows, int cols, float *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    MatrixF *res = (MatrixF*)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(float) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = data[i];
        }
    }
    return res;
}

MatrixF *create_matrixf_d(int rows, int cols, double *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    float *new_data = transfrom_pointerd2f(data, len);
    MatrixF *res = (MatrixF*)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(float) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixF *create_matrixf_c(int rows, int cols, Complex *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    float *new_data = transfrom_pointerc2f(data, len);
    MatrixF *res = (MatrixF*)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (float*)malloc(sizeof(float) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(float) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixD *create_matrixd_i(int rows, int cols, int *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    double *new_data = transfrom_pointeri2d(data, len);
    MatrixD *res = (MatrixD*)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (double*)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixD *create_matrixd_f(int rows, int cols, float *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    double *new_data = transfrom_pointerf2d(data, len);
    MatrixD *res = (MatrixD*)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (double*)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixD *create_matrixd_d(int rows, int cols, double *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    MatrixD *res = (MatrixD*)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (double*)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = data[i];
        }
    }
    return res;
}

MatrixD *create_matrixd_c(int rows, int cols, Complex *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    double *new_data = transfrom_pointerc2d(data, len);
    MatrixD *res = (MatrixD*)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (double*)malloc(sizeof(double) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(double) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixC *create_matrixc_i(int rows, int cols, int *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    Complex *new_data = transfrom_pointeri2c(data, len);
    MatrixC *res = (MatrixC*)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (Complex*)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixC *create_matrixc_f(int rows, int cols, float *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    Complex *new_data = transfrom_pointerf2c(data, len);
    MatrixC *res = (MatrixC*)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (Complex*)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixC *create_matrixc_d(int rows, int cols, double *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    Complex *new_data = transfrom_pointerd2c(data, len);
    MatrixC *res = (MatrixC*)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (Complex*)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = new_data[i];
        }
    }
    return res;
}

MatrixC *create_matrixc_c(int rows, int cols, Complex *data, size_t len)
{
    if(data == NULL)
    {
        printf("data is NULL!\n");
        return NULL;
    }
    MatrixC *res = (MatrixC*)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->rows = rows;
    res->cols = cols;
    res->data = (Complex*)malloc(sizeof(Complex) * res->rows * res->cols);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    memset(res->data, 0, sizeof(Complex) * res->cols * res->rows);
    if(len > rows * cols)
    {
        for (size_t i = 0; i < rows * cols; i++)
        {
            res->data[i] = data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            res->data[i] = data[i];
        }
    }
    return res;
}