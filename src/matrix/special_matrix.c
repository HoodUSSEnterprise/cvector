#include "matrix/special_matrix.h"
#include "tools/max_min.h"

MatrixI *identity_matrixi(int order)
{
    int *data = (int*)malloc(sizeof(int) * order * order);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    memset(data, 0, sizeof(int) * order * order);
    for (size_t i = 0; i < order; i++)
    {
        data[i * order + i] = 1;
    }
    return create_matrixi(order, order, data, order * order);
}

MatrixF *identity_matrixf(int order)
{
    float *data = (float*)malloc(sizeof(float) * order * order);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    memset(data, 0, sizeof(float) * order * order);
    for (size_t i = 0; i < order; i++)
    {
        data[i * order + i] = 1.0f;
    }
    return create_matrixf(order, order, data, order * order);
}

MatrixD *identity_matrixd(int order)
{
    double *data = (double*)malloc(sizeof(double) * order * order);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    memset(data, 0, sizeof(double) * order * order);
    for (size_t i = 0; i < order; i++)
    {
        data[i * order + i] = 1.0;
    }
    return create_matrixd(order, order, data, order * order);
}

MatrixC *identity_matrixc(int order)
{
    Complex *data = (Complex*)malloc(sizeof(Complex) * order * order);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    memset(data, 0, sizeof(Complex) * order * order);
    for (size_t i = 0; i < order; i++)
    {
        data[i * order + i] = (Complex){1, 0};
    }
    return create_matrixc(order, order, data, order * order);
}

MatrixI *diag_matrixi_i(const int *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    int *new_data = (int*)malloc(sizeof(int) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = data[i];
    }
    return create_matrixi(len, len, new_data, len * len);
}

MatrixI *diag_matrixi_f(const float *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    int *new_data = (int*)malloc(sizeof(int) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (int)data[i];
    }
    return create_matrixi(len, len, new_data, len * len);
}

MatrixI *diag_matrixi_d(const double *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    int *new_data = (int*)malloc(sizeof(int) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (int)data[i];
    }
    return create_matrixi(len, len, new_data, len * len);
}

MatrixI *diag_matrixi_c(const Complex *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    int *new_data = (int*)malloc(sizeof(int) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (int)data[i].real;
    }
    return create_matrixi(len, len, new_data, len * len);
}

MatrixF *diag_matrixf_i(const int *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    float *new_data = (float*)malloc(sizeof(float) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (float)data[i];
    }
    return create_matrixf(len, len, new_data, len * len);
}

MatrixF *diag_matrixf_f(const float *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    float *new_data = (float*)malloc(sizeof(float) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = data[i];
    }
    return create_matrixf(len, len, new_data, len * len);
}

MatrixF *diag_matrixf_d(const double *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    float *new_data = (float*)malloc(sizeof(float) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (float)data[i];
    }
    return create_matrixf(len, len, new_data, len * len);
}

MatrixF *diag_matrixf_c(const Complex *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    float *new_data = (float*)malloc(sizeof(float) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (float)data[i].real;
    }
    return create_matrixf(len, len, new_data, len * len);
}

MatrixD *diag_matrixd_i(const int *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    double *new_data = (double*)malloc(sizeof(double) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (double)data[i];
    }
    return create_matrixd(len, len, new_data, len * len);
}

MatrixD *diag_matrixd_f(const float *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    double *new_data = (double*)malloc(sizeof(double) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (double)data[i];
    }
    return create_matrixd(len, len, new_data, len * len);
}

MatrixD *diag_matrixd_d(const double *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    double *new_data = (double*)malloc(sizeof(double) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = data[i];
    }
    return create_matrixd(len, len, new_data, len * len);
}

MatrixD *diag_matrixd_c(const Complex *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    double *new_data = (double*)malloc(sizeof(double) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (double)data[i].real;
    }
    return create_matrixd(len, len, new_data, len * len);
}

MatrixC *diag_matrixc_i(const int *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    Complex *new_data = (Complex*)malloc(sizeof(Complex) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (Complex){data[i], 0};
    }
    return create_matrixc(len, len, new_data, len * len);
}

MatrixC *diag_matrixc_f(const float *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    Complex *new_data = (Complex*)malloc(sizeof(Complex) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (Complex){data[i], 0};
    }
    return create_matrixc(len, len, new_data, len * len);
}

MatrixC *diag_matrixc_d(const double *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    Complex *new_data = (Complex*)malloc(sizeof(Complex) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = (Complex){data[i], 0};
    }
    return create_matrixc(len, len, new_data, len * len);
}

MatrixC *diag_matrixc_c(const Complex *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param\n");
        return NULL;
    }
    Complex *new_data = (Complex*)malloc(sizeof(Complex) * len * len);
    if (new_data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        new_data[i * len + i] = data[i];
    }
    return create_matrixc(len, len, new_data, len * len);
}

MatrixI *eye_matrixi(int rows, int cols)
{
    int min_val = min(rows, cols);
    int *data = (int*)malloc(sizeof(int) * rows * cols);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < min_val; i++)
    {
        data[i * cols + i] = 1;
    }
    return create_matrixi(rows, cols, data, rows * cols);
}

MatrixF *eye_matrixf(int rows, int cols)
{
    int min_val = min(rows, cols);
    float *data = (float*)malloc(sizeof(float) * rows * cols);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < min_val; i++)
    {
        data[i * cols + i] = 1.0f;
    }
    return create_matrixf(rows, cols, data, rows * cols);
}

MatrixD *eye_matrixd(int rows, int cols)
{
    int min_val = min(rows, cols);
    double *data = (double*)malloc(sizeof(double) * rows * cols);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < min_val; i++)
    {
        data[i * cols + i] = 1.0;
    }
    return create_matrixd(rows, cols, data, rows * cols);
}

MatrixC *eye_matrixc(int rows, int cols)
{
    int min_val = min(rows, cols);
    Complex *data = (Complex*)malloc(sizeof(Complex) * rows * cols);
    if (data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < min_val; i++)
    {
        data[i * cols + i] = (Complex){1, 0};
    }
    return create_matrixc(rows, cols, data, rows * cols);
}