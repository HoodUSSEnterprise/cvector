#include "vector/print_vector.h"
#include <math.h>

void print_vector2i(Vector2i *v)
{
    printf("(%d, %d)\n", v->x, v->y);
}

void print_vector2f(Vector2f *v)
{
    printf("(%f, %f)\n", v->x, v->y);
}

void print_vector2d(Vector2d *v)
{
    printf("(%f, %f)\n", v->x, v->y);
}

void print_vector2c(Vector2c *v)
{
    char x[100];
    sprintf(x, "%lf%s%lfi", v->x.real, (v->x.imag >= 0 ? " + " : " - "), fabs(v->x.imag));
    char y[100];
    sprintf(y, "%lf%s%lfi", v->y.real, (v->y.imag >= 0 ? " + " : " - "), fabs(v->y.imag));
    printf("(%s, %s)\n", x, y);
}

void print_vector3i(Vector3i *v)
{
    printf("(%d, %d, %d)\n", v->x, v->y, v->z);
}

void print_vector3f(Vector3f *v)
{
    printf("(%f, %f, %f)\n", v->x, v->y, v->z);
}

void print_vector3d(Vector3d *v)
{
    printf("(%lf, %lf, %lf)\n", v->x, v->y, v->z);
}

void print_vector3c(Vector3c *v)
{
    char x[100];
    sprintf(x, "%lf%s%lfi", v->x.real, (v->x.imag >= 0 ? " + " : " - "), fabs(v->x.imag));
    char y[100];
    sprintf(y, "%lf%s%lfi", v->y.real, (v->y.imag >= 0 ? " + " : " - "), fabs(v->y.imag));
    char z[100];
    sprintf(z, "%lf%s%lfi", v->z.real, (v->z.imag >= 0 ? " + " : " - "), fabs(v->z.imag));
    printf("(%s, %s, %s)\n", x, y, z);
}

void print_vectori(Vectori *v)
{
    if (v->len == 0)
    {
        printf("\n");
    }
    else if (v->len == 1)
    {
        printf("(%d)\n", v->data[0]);
    }
    else
    {
        printf("(%d", v->data[0]);
        for (size_t i = 1; i < v->len; i++)
        {
            printf(", %d", v->data[i]);
        }
        printf(")\n");
    }
}

void print_vectorf(Vectorf *v)
{
    if (v->len == 0)
    {
        printf("\n");
    }
    else if (v->len == 1)
    {
        printf("(%f)\n", v->data[0]);
    }
    else
    {
        printf("(%f", v->data[0]);
        for (size_t i = 1; i < v->len; i++)
        {
            printf(", %f", v->data[i]);
        }
        printf(")\n");
    }
}

void print_vectord(Vectord *v)
{
    if (v->len == 0)
    {
        printf("\n");
    }
    else if (v->len == 1)
    {
        printf("(%lf)\n", v->data[0]);
    }
    else
    {
        printf("(%lf", v->data[0]);
        for (size_t i = 1; i < v->len; i++)
        {
            printf(", %lf", v->data[i]);
        }
        printf(")\n");
    }
}

void print_vectorc(Vectorc *v)
{
    if (v->len == 0)
    {
        printf("\n");
    }
    else if (v->len == 1)
    {
        char x[100];
        sprintf(x, "%lf%s%lfi", v->data[0].real, (v->data[0].imag >= 0 ? " + " : " - "), fabs(v->data[0].imag));
        printf("(%s)\n", x);
    }
    else
    {
        char first[100];
        sprintf(first, "%lf%s%lfi", v->data[0].real, (v->data[0].imag >= 0 ? " + " : " - "), fabs(v->data[0].imag));
        printf("(%s", first);
        for (size_t i = 1; i < v->len; i++)
        {
            char x[100];
            sprintf(x, "%lf%s%lfi", v->data[i].real, (v->data[i].imag >= 0 ? " + " : " - "), fabs(v->data[i].imag));
            printf(", %s", x);
        }
        printf(")\n");
    }
}