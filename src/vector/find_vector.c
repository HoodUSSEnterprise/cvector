#include "vector/find_vector.h"

int find_vector2i(Vector2i *v, int elem)
{
    return v->x == elem ? 0 : (v->y == elem ? 1 : -1);
}

int find_vector2f(Vector2f *v, float elem)
{
    return fabs(v->x - elem) < 1e-6 ? 0 : (fabs(v->y - elem) < 1e-6 ? 1 : -1);
    // return v->x == elem ? 0 : (v->y == elem ? 1 : -1); //简单判断
}

int find_vector2d(Vector2d *v, double elem)
{
    return fabs(v->x - elem) < 1e-6 ? 0 : (fabs(v->y - elem) < 1e-6 ? 1 : -1);
    // return v->x == elem ? 0 : (v->y == elem ? 1 : -1); //简单判断
}

int find_vector2c(Vector2c *v, Complex elem)
{
    return is_equal_complex(v->x, elem) ? 0 : (is_equal_complex(v->y, elem) ? 1 : -1);
    // return v->x == elem ? 0 : (v->y == elem ? 1 : -1); //简单判断
}

int find_vector3i(Vector3i *v, int elem)
{
    if (v->x == elem)
    {
        return 0;
    }
    else if (v->y == elem)
    {
        return 1;
    }
    else if (v->z == elem)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int find_vector3f(Vector3f *v, float elem)
{
    if (fabs(v->x - elem) < 1e-6)
    {
        return 0;
    }
    else if (fabs(v->y - elem) < 1e-6)
    {
        return 1;
    }
    else if (fabs(v->z - elem) < 1e-6)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int find_vector3d(Vector3d *v, double elem)
{
    if (fabs(v->x - elem) < 1e-6)
    {
        return 0;
    }
    else if (fabs(v->y - elem) < 1e-6)
    {
        return 1;
    }
    else if (fabs(v->z - elem) < 1e-6)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int find_vector3c(Vector3c *v, Complex elem)
{
    if (is_equal_complex(v->x, elem))
    {
        return 0;
    }
    else if (is_equal_complex(v->y, elem))
    {
        return 1;
    }
    else if (is_equal_complex(v->z, elem))
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int find_vectori(Vectori *v, int elem)
{
    if (v->len == 0)
    {
        return -1;
    }

    for (size_t i = 0; i < v->len; i++)
    {
        if (v->data[i] == elem)
        {
            return i;
        }
    }

    return -1;
}

int find_vectorf(Vectorf *v, float elem)
{
    if (v->len == 0)
    {
        return -1;
    }

    for (size_t i = 0; i < v->len; i++)
    {
        if (fabs(v->data[i] - elem) < 1e-6)
        {
            return i;
        }
    }

    return -1;
}

int find_vectord(Vectord *v, double elem)
{
    if (v->len == 0)
    {
        return -1;
    }

    for (size_t i = 0; i < v->len; i++)
    {
        if (fabs(v->data[i] - elem) < 1e-6)
        {
            return i;
        }
    }

    return -1;
}

int find_vectorc(Vectorc *v, Complex elem)
{
    if (v->len == 0)
    {
        return -1;
    }

    for (size_t i = 0; i < v->len; i++)
    {
        if (is_equal_complex(v->data[i], elem))
        {
            return i;
        }
    }

    return -1;
}