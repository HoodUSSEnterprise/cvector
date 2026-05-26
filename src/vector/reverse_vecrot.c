#include "vector/reverse_vector.h"

void reverse_vector2i(Vector2i **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector2i *res = (Vector2i*)malloc(sizeof(Vector2i));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->y;
    res->y = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vector2f(Vector2f **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector2f *res = (Vector2f*)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->y;
    res->y = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vector2d(Vector2d **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector2d *res = (Vector2d*)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->y;
    res->y = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vector2c(Vector2c **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector2c *res = (Vector2c*)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->y;
    res->y = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vector3i(Vector3i **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector3i *res = (Vector3i*)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->z;
    res->y = (*v)->y;
    res->z = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vector3f(Vector3f **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector3f *res = (Vector3f*)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->z;
    res->y = (*v)->y;
    res->z = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vector3d(Vector3d **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector3d *res = (Vector3d*)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->z;
    res->y = (*v)->y;
    res->z = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vector3c(Vector3c **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vector3c *res = (Vector3c*)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->x = (*v)->z;
    res->y = (*v)->y;
    res->z = (*v)->x;
    free((*v));
    *v = res;
}

void reverse_vectori(Vectori **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vectori *res = (Vectori*)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->len = (*v)->len;
    res->data = (int*)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[res->len - i - 1];
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void reverse_vectorf(Vectorf **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vectorf *res = (Vectorf*)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->len = (*v)->len;
    res->data = (float*)malloc(sizeof(float) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[res->len - i - 1];
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void reverse_vectord(Vectord **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vectord *res = (Vectord*)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->len = (*v)->len;
    res->data = (double*)malloc(sizeof(double) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[res->len - i - 1];
    }
    free((*v)->data);
    free((*v));
    *v = res;
}

void reverse_vectorc(Vectorc **v)
{
    if(v == NULL || *v == NULL)
    {
        return;
    }
    Vectorc *res = (Vectorc*)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        return;
    }
    res->len = (*v)->len;
    res->data = (Complex*)malloc(sizeof(Complex) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        res->data[i] = (*v)->data[res->len - i - 1];
    }
    free((*v)->data);
    free((*v));
    *v = res;
}