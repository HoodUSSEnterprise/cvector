#include "vector/create_vector.h"

Vector2i *create_vector2i(int x, int y)
{
    Vector2i *res = (Vector2i *)malloc(sizeof(Vector2i));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    return res;
}

Vector2f *create_vector2f(float x, float y)
{
    Vector2f *res = (Vector2f *)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    return res;
}

Vector2d *create_vector2d(double x, double y)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    return res;
}

Vector2c *create_vector2c(Complex x, Complex y)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    return res;
}

Vector3i *create_vector3i(int x, int y, int z)
{
    Vector3i *res = (Vector3i *)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    res->z = z;
    return res;
}

Vector3f *create_vector3f(float x, float y, float z)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    res->z = z;
    return res;
}

Vector3d *create_vector3d(double x, double y, double z)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    res->z = z;
    return res;
}

Vector3c *create_vector3c(Complex x, Complex y, Complex z)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = x;
    res->y = y;
    res->z = z;
    return res;
}

Vectori *create_vectori(unsigned int len, int *data)
{
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = len;
    res->data = (int *)malloc(sizeof(int) * len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    memcpy(res->data, data, sizeof(int) * res->len);
    return res;
}

Vectorf *create_vectorf(unsigned int len, float *data)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = len;
    res->data = (float *)malloc(sizeof(float) * len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    memcpy(res->data, data, sizeof(float) * res->len);
    return res;
}

Vectord *create_vectord(unsigned int len, double *data)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = len;
    res->data = (double *)malloc(sizeof(double) * len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    memcpy(res->data, data, sizeof(double) * res->len);
    return res;
}

Vectorc *create_vectorc(unsigned int len, Complex *data)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = len;
    res->data = (Complex *)malloc(sizeof(Complex) * len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    memcpy(res->data, data, sizeof(Complex) * res->len);
    return res;
}
