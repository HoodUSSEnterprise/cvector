#include "tools/pointer_transform.h"

int *transfrom_pointerf2i(float *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    int *res = (int*)malloc(sizeof(int) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (int)data[i];
    }
    return res;
}

int *transfrom_pointerd2i(double *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    int *res = (int*)malloc(sizeof(int) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (int)data[i];
    }
    return res;
}

int *transfrom_pointerc2i(Complex *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    int *res = (int*)malloc(sizeof(int) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (int)data[i].real;
    }
    return res;
}

float *transfrom_pointeri2f(int *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    float *res = (float*)malloc(sizeof(float) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (float)data[i];
    }
    return res;
}

float *transfrom_pointerd2f(double *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    float *res = (float*)malloc(sizeof(float) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (float)data[i];
    }
    return res;
}

float *transfrom_pointerc2f(Complex *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    float *res = (float*)malloc(sizeof(float) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (float)data[i].real;
    }
    return res;
}

double *transfrom_pointeri2d(int *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    double *res = (double*)malloc(sizeof(double) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (double)data[i];
    }
    return res;
}

double *transfrom_pointerf2d(float *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    double *res = (double*)malloc(sizeof(double) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (double)data[i];
    }
    return res;
}

double *transfrom_pointerc2d(Complex *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    double *res = (double*)malloc(sizeof(double) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (double)data[i].real;
    }
    return res;
}

Complex *transfrom_pointeri2c(int *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    Complex *res = (Complex*)malloc(sizeof(Complex) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (Complex){data[i], 0};
    }
    return res;
}

Complex *transfrom_pointerf2c(float *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    Complex *res = (Complex*)malloc(sizeof(Complex) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (Complex){data[i], 0};
    }
    return res;
}


Complex *transfrom_pointerd2c(double *data, size_t len)
{
    if(data == NULL || len == 0)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    Complex *res = (Complex*)malloc(sizeof(Complex) * len);
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        res[i] = (Complex){data[i], 0};
    }
    return res;
}
