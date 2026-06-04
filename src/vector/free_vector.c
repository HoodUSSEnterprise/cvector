#include "vector/free_vector.h"

void free_vector2i(Vector2i **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vector2f(Vector2f **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vector2d(Vector2d **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vector2c(Vector2c **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vector3i(Vector3i **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vector3f(Vector3f **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vector3d(Vector3d **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vector3c(Vector3c **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        free(*v);
        *v = NULL;
    }
}

void free_vectori(Vectori **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        if ((*v)->data != NULL)
        {
            free((*v)->data);
            (*v)->data = NULL;
        }
        free(*v);
        *v = NULL;
    }
}

void free_vectorf(Vectorf **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        if ((*v)->data != NULL)
        {
            free((*v)->data);
            (*v)->data = NULL;
        }
        free(*v);
        *v = NULL;
    }
}

void free_vectord(Vectord **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        if ((*v)->data != NULL)
        {
            free((*v)->data);
            (*v)->data = NULL;
        }
        free(*v);
        *v = NULL;
    }
}

void free_vectorc(Vectorc **v)
{
    if (v == NULL || *v == NULL)
    {
        return;
    }
    else
    {
        if ((*v)->data != NULL)
        {
            free((*v)->data);
            (*v)->data = NULL;
        }
        free(*v);
        *v = NULL;
    }
}
