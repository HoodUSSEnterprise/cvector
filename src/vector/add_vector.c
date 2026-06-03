#include "vector/operator_vector.h"

Vectori *Nonei = NULL;
Vectorf *Nonef = NULL;
Vectord *Noned = NULL;
Vectorc *Nonec = NULL;

//  ============ Vector2i  ============
Vector2i *add_vector2i_2i(const Vector2i *v1, const Vector2i *v2)
{
    Vector2i *res = (Vector2i *)malloc(sizeof(Vector2i));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2f *add_vector2i_2f(const Vector2i *v1, const Vector2f *v2)
{
    Vector2f *res = (Vector2f *)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2i_2d(const Vector2i *v1, const Vector2d *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2c *add_vector2i_2c(const Vector2i *v1, const Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    return res;
}

Vector3i *add_vector2i_3i(const Vector2i *v1, const Vector3i *v2)
{
    Vector3i *res = (Vector3i *)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3f *add_vector2i_3f(const Vector2i *v1, const Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2i_3d(const Vector2i *v1, const Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3c *add_vector2i_3c(const Vector2i *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = v2->z;
    return res;
}

Vectori *add_vector2i_i(const Vector2i *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectori *res = (Vectori *)malloc(sizeof(Vectori));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        return res;
    }
    else
    {
        Vectori *res = (Vectori *)malloc(sizeof(Vectori));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len >= i - 1 ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorf *add_vector2i_f(const Vector2i *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        return (Vectorf *)v1;
    }
    else
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (float *)malloc(sizeof(float) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector2i_d(const Vector2i *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        return (Vectord *)v1;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorc *add_vector2i_c(const Vector2i *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        res->data[0] = (Complex){v1->x, 0};
        res->data[1] = (Complex){v1->y, 0};
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex((Complex){v1->x, 0}, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex((Complex){v1->x, 0}, (v2->len >= i - 1 ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vector2f  ============
Vector2f *add_vector2f_2i(const Vector2f *v1, const Vector2i *v2)
{
    Vector2f *res = (Vector2f *)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2f *add_vector2f_2f(const Vector2f *v1, const Vector2f *v2)
{
    Vector2f *res = (Vector2f *)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2f_2d(const Vector2f *v1, const Vector2d *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2c *add_vector2f_2c(const Vector2f *v1, const Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    return res;
}

Vector3f *add_vector2f_3i(const Vector2f *v1, const Vector3i *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3f *add_vector2f_3f(const Vector2f *v1, const Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2f_3d(const Vector2f *v1, const Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3c *add_vector2f_3c(const Vector2f *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = v2->z;
    return res;
}

Vectorf *add_vector2f_i(const Vector2f *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        return (Vectorf *)v1;
    }
    else
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (float *)malloc(sizeof(float) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorf *add_vector2f_f(const Vector2f *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        return (Vectorf *)v1;
    }
    else
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (float *)malloc(sizeof(float) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector2f_d(const Vector2f *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        return (Vectord *)v1;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorc *add_vector2f_c(const Vector2f *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        res->data[0] = (Complex){v1->x, 0};
        res->data[1] = (Complex){v1->y, 0};
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex((Complex){v1->x, 0}, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex((Complex){v1->y, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vector2d  ============
Vector2d *add_vector2d_2i(const Vector2d *v1, const Vector2i *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2d_2f(const Vector2d *v1, const Vector2f *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2d_2d(const Vector2d *v1, const Vector2d *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2c *add_vector2d_2c(const Vector2d *v1, const Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    return res;
}

Vector3d *add_vector2d_3i(const Vector2d *v1, const Vector3i *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2d_3f(const Vector2d *v1, const Vector3f *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2d_3d(const Vector2d *v1, const Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3c *add_vector2d_3c(const Vector2d *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = v2->z;
    return res;
}

Vectord *add_vector2d_i(const Vector2d *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        return (Vectord *)v1;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector2d_f(const Vector2d *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        return (Vectord *)v1;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector2d_d(const Vector2d *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        return (Vectord *)v1;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorc *add_vector2d_c(const Vector2d *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        res->data[0] = (Complex){v1->x, 0};
        res->data[1] = (Complex){v1->y, 0};
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex((Complex){v1->x, 0}, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex((Complex){v1->y, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vector2c  ============
Vector2c *add_vector2c_2i(const Vector2c *v1, const Vector2i *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    return res;
}

Vector2c *add_vector2c_2f(const Vector2c *v1, const Vector2f *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    return res;
}

Vector2c *add_vector2c_2d(const Vector2c *v1, const Vector2d *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    return res;
}

Vector2c *add_vector2c_2c(const Vector2c *v1, const Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    return res;
}

Vector3c *add_vector2c_3i(const Vector2c *v1, const Vector3i *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = (Complex){v2->z, 0};
    return res;
}

Vector3c *add_vector2c_3f(const Vector2c *v1, const Vector3f *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = (Complex){v2->z, 0};
    return res;
}

Vector3c *add_vector2c_3d(const Vector2c *v1, const Vector3d *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = (Complex){v2->z, 0};
    return res;
}

Vector3c *add_vector2c_3c(const Vector2c *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    res->z = v2->z;
    return res;
}

Vectorc *add_vector2c_i(const Vector2c *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, (Complex){v2->data[0], 0});
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else
            {
                res->data[i] = (Complex){v2->data[i], 0};
            }
        }
        return res;
    }
}

Vectorc *add_vector2c_f(const Vector2c *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, (Complex){v2->data[0], 0});
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else
            {
                res->data[i] = (Complex){v2->data[i], 0};
            }
        }
        return res;
    }
}

Vectorc *add_vector2c_d(const Vector2c *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, (Complex){v2->data[0], 0});
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else
            {
                res->data[i] = (Complex){v2->data[i], 0};
            }
        }
        return res;
    }
}

Vectorc *add_vector2c_c(const Vector2c *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 2;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vector3i  ============
Vector3i *add_vector3i_2i(const Vector3i *v1, const Vector2i *v2)
{
    Vector3i *res = (Vector3i *)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3f *add_vector3i_2f(const Vector3i *v1, const Vector2f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3i_2d(const Vector3i *v1, const Vector2d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3i_2c(const Vector3i *v1, const Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = (Complex){v1->z, 0};
    return res;
}

Vector3i *add_vector3i_3i(const Vector3i *v1, const Vector3i *v2)
{
    Vector3i *res = (Vector3i *)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3f *add_vector3i_3f(const Vector3i *v1, const Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3i_3d(const Vector3i *v1, const Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3c *add_vector3i_3c(const Vector3i *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = add_complex((Complex){v1->z, 0}, v2->z);
    return res;
}

Vectori *add_vector3i_i(const Vector3i *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectori *res = (Vectori *)malloc(sizeof(Vectori));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (int *)malloc(sizeof(int) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectori *res = (Vectori *)malloc(sizeof(Vectori));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorf *add_vector3i_f(const Vector3i *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (float *)malloc(sizeof(float) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (float *)malloc(sizeof(float) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector3i_d(const Vector3i *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (double *)malloc(sizeof(double) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorc *add_vector3i_c(const Vector3i *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (Complex *)malloc(sizeof(Complex) * 3);
        res->data[0] = (Complex){v1->x, 0};
        res->data[1] = (Complex){v1->y, 0};
        res->data[2] = (Complex){v1->z, 0};
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex((Complex){v1->x, 0}, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex((Complex){v1->y, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else if (i == 2)
            {
                res->data[2] = add_complex((Complex){v1->z, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vector3f  ============
Vector3f *add_vector3f_2i(const Vector3f *v1, const Vector2i *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3f *add_vector3f_2f(const Vector3f *v1, const Vector2f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3f_2d(const Vector3f *v1, const Vector2d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3f_2c(const Vector3f *v1, const Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = (Complex){v1->z, 0};
    return res;
}

Vector3f *add_vector3f_3i(const Vector3f *v1, const Vector3i *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3f *add_vector3f_3f(const Vector3f *v1, const Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3f_3d(const Vector3f *v1, const Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3c *add_vector3f_3c(const Vector3f *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = add_complex((Complex){v1->z, 0}, v2->z);
    return res;
}

Vectorf *add_vector3f_i(const Vector3f *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (float *)malloc(sizeof(float) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (float *)malloc(sizeof(float) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorf *add_vector3f_f(const Vector3f *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (float *)malloc(sizeof(float) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (float *)malloc(sizeof(float) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector3f_d(const Vector3f *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (double *)malloc(sizeof(double) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorc *add_vector3f_c(const Vector3f *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (Complex *)malloc(sizeof(Complex) * 3);
        res->data[0] = (Complex){v1->x, 0};
        res->data[1] = (Complex){v1->y, 0};
        res->data[2] = (Complex){v1->z, 0};
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex((Complex){v1->x, 0}, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex((Complex){v1->y, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else if (i == 2)
            {
                res->data[2] = add_complex((Complex){v1->z, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vector3d  ============
Vector3d *add_vector3d_2i(const Vector3d *v1, const Vector2i *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3d_2f(const Vector3d *v1, const Vector2f *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3d_2d(const Vector3d *v1, const Vector2d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3d_2c(const Vector3d *v1, const Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = (Complex){v1->z, 0};
    return res;
}

Vector3d *add_vector3d_3i(const Vector3d *v1, const Vector3i *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3d_3f(const Vector3d *v1, const Vector3f *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3d_3d(const Vector3d *v1, const Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3c *add_vector3d_3c(const Vector3d *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = add_complex((Complex){v1->z, 0}, v2->z);
    return res;
}

Vectord *add_vector3d_i(const Vector3d *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (double *)malloc(sizeof(double) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector3d_f(const Vector3d *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (double *)malloc(sizeof(double) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectord *add_vector3d_d(const Vector3d *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (double *)malloc(sizeof(double) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (double *)malloc(sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = v1->x + v2->data[0];
            }
            else if (i == 1)
            {
                res->data[1] = v1->y + (v2->len > i ? v2->data[i] : 0);
            }
            else if (i == 2)
            {
                res->data[2] = v1->z + (v2->len > i ? v2->data[i] : 0);
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

Vectorc *add_vector3d_c(const Vector3d *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (Complex *)malloc(sizeof(Complex) * 3);
        res->data[0] = (Complex){v1->x, 0};
        res->data[1] = (Complex){v1->y, 0};
        res->data[2] = (Complex){v1->z, 0};
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex((Complex){v1->x, 0}, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex((Complex){v1->y, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else if (i == 2)
            {
                res->data[2] = add_complex((Complex){v1->z, 0}, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vector3c  ============
Vector3c *add_vector3c_2i(const Vector3c *v1, const Vector2i *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_2f(const Vector3c *v1, const Vector2f *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_2d(const Vector3c *v1, const Vector2d *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_2c(const Vector3c *v1, const Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_3i(const Vector3c *v1, const Vector3i *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = add_complex(v1->z, (Complex){v2->z, 0});
    return res;
}

Vector3c *add_vector3c_3f(const Vector3c *v1, const Vector3f *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = add_complex(v1->z, (Complex){v2->z, 0});
    return res;
}

Vector3c *add_vector3c_3d(const Vector3c *v1, const Vector3d *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = add_complex(v1->z, (Complex){v2->z, 0});
    return res;
}

Vector3c *add_vector3c_3c(const Vector3c *v1, const Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    res->z = add_complex(v1->z, v2->z);
    return res;
}

Vectorc *add_vector3c_i(const Vector3c *v1, const Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (Complex *)malloc(sizeof(Complex) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, (Complex){v2->data[0], 0});
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else if (i == 2)
            {
                res->data[2] = add_complex(v1->z, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else
            {
                res->data[i] = (Complex){v2->data[i], 0};
            }
        }
        return res;
    }
}

Vectorc *add_vector3c_f(const Vector3c *v1, const Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (Complex *)malloc(sizeof(Complex) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, (Complex){v2->data[0], 0});
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else if (i == 2)
            {
                res->data[2] = add_complex(v1->z, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else
            {
                res->data[i] = (Complex){v2->data[i], 0};
            }
        }
        return res;
    }
}

Vectorc *add_vector3c_d(const Vector3c *v1, const Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (Complex *)malloc(sizeof(Complex) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, (Complex){v2->data[0], 0});
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else if (i == 2)
            {
                res->data[2] = add_complex(v1->z, (Complex){(v2->len > i ? v2->data[i] : 0), 0});
            }
            else
            {
                res->data[i] = (Complex){v2->data[i], 0};
            }
        }
        return res;
    }
}

Vectorc *add_vector3c_c(const Vector3c *v1, const Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 3;
        res->data = (Complex *)malloc(sizeof(Complex) * 3);
        res->data[0] = v1->x;
        res->data[1] = v1->y;
        res->data[2] = v1->z;
        return res;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            if (i == 0)
            {
                res->data[0] = add_complex(v1->x, v2->data[0]);
            }
            else if (i == 1)
            {
                res->data[1] = add_complex(v1->y, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else if (i == 2)
            {
                res->data[2] = add_complex(v1->z, (v2->len > i ? v2->data[i] : (Complex){0, 0}));
            }
            else
            {
                res->data[i] = v2->data[i];
            }
        }
        return res;
    }
}

// ============ Vectori  ============
Vectori *add_vectori_2i(const Vectori *v1, const Vector2i *v2)
{
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        int a = (v1->len > i ? v1->data[i] : 0);
        int b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectorf *add_vectori_2f(const Vectori *v1, const Vector2f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectori_2d(const Vectori *v1, const Vector2d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectori_2c(const Vectori *v1, const Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (Complex){0, 0}));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectori *add_vectori_3i(const Vectori *v1, const Vector3i *v2)
{
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    for (size_t i = 0; i < res->len; i++)
    {
        int a = (v1->len > i ? v1->data[i] : 0);
        int b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectorf *add_vectori_3f(const Vectori *v1, const Vector3f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectori_3d(const Vectori *v1, const Vector3d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectori_3c(const Vectori *v1, const Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : (Complex){0, 0})));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectori *add_vectori_i(const Vectori *v1, const Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        return Nonei;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    if (v1->len == v2->len)
    {
        res->len = v1->len;
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        for (size_t i = 0; i < res->len; i++)
        {
            res->data[i] = v1->data[i] + v2->data[i];
        }
        return 0;
    }
    else
    {
        res->len = v1->len >= v2->len ? v1->len : v2->len;
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        for (size_t i = 0; i < res->len; i++)
        {
            int a = (v1->len - 1 >= i ? v1->data[i] : 0);
            int b = (v2->len - 1 >= i ? v2->data[i] : 0);
            res->data[i] = a + b;
        }
        return res;
    }
}

Vectorf *add_vectori_f(const Vectori *v1, const Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectori_d(const Vectori *v1, const Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectori_c(const Vectori *v1, const Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        return Nonec;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    if (v1->len == v2->len)
    {
        res->len = v1->len;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            res->data[i] = add_complex((Complex){v1->data[i], 0}, v2->data[i]);
        }
        return 0;
    }
    else
    {
        res->len = v1->len >= v2->len ? v1->len : v2->len;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            int a = (v1->len - 1 >= i ? v1->data[i] : 0);
            Complex b = (v2->len - 1 >= i ? v2->data[i] : (Complex){0, 0});
            res->data[i] = add_complex((Complex){a, 0}, b);
        }
        return res;
    }
}

// ============ Vectorf  ============
Vectorf *add_vectorf_2i(const Vectorf *v1, const Vector2i *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectorf *add_vectorf_2f(const Vectorf *v1, const Vector2f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectorf_2d(const Vectorf *v1, const Vector2d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectorf_2c(const Vectorf *v1, const Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (Complex){0, 0}));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorf *add_vectorf_3i(const Vectorf *v1, const Vector3i *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectorf *add_vectorf_3f(const Vectorf *v1, const Vector3f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectorf_3d(const Vectorf *v1, const Vector3d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectorf_3c(const Vectorf *v1, const Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : (Complex){0, 0})));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorf *add_vectorf_i(const Vectorf *v1, const Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectorf *add_vectorf_f(const Vectorf *v1, const Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (float *)malloc(sizeof(float) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        float a = (v1->len > i ? v1->data[i] : 0);
        float b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectorf_d(const Vectorf *v1, const Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectorf_c(const Vectorf *v1, const Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (v2->len > i ? v2->data[i] : (Complex){0, 0});
        res->data[i] = add_complex(a, b);
    }
    return res;
}

// ============ Vectord  ============
Vectord *add_vectord_2i(const Vectord *v1, const Vector2i *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectord_2f(const Vectord *v1, const Vector2f *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectord_2d(const Vectord *v1, const Vector2d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectord_2c(const Vectord *v1, const Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (Complex){0, 0}));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectord *add_vectord_3i(const Vectord *v1, const Vector3i *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectord_3f(const Vectord *v1, const Vector3f *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectord_3d(const Vectord *v1, const Vector3d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectord_3c(const Vectord *v1, const Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : (Complex){0, 0})));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectord *add_vectord_i(const Vectord *v1, const Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectord_f(const Vectord *v1, const Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectord *add_vectord_d(const Vectord *v1, const Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (double *)malloc(sizeof(double) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        double a = (v1->len > i ? v1->data[i] : 0);
        double b = (v2->len > i ? v2->data[i] : 0);
        res->data[i] = a + b;
    }
    return res;
}

Vectorc *add_vectord_c(const Vectord *v1, const Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? (Complex){v1->data[i], 0} : (Complex){0, 0});
        Complex b = (v2->len > i ? v2->data[i] : (Complex){0, 0});
        res->data[i] = add_complex(a, b);
    }
    return res;
}

// ============ Vectorc  ============
Vectorc *add_vectorc_2i(const Vectorc *v1, const Vector2i *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? (Complex){v2->x, 0} : (i == 1 ? (Complex){v2->y, 0} : (Complex){0, 0}));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_2f(const Vectorc *v1, const Vector2f *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? (Complex){v2->x, 0} : (i == 1 ? (Complex){v2->y, 0} : (Complex){0, 0}));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_2d(const Vectorc *v1, const Vector2d *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? (Complex){v2->x, 0} : (i == 1 ? (Complex){v2->y, 0} : (Complex){0, 0}));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_2c(const Vectorc *v1, const Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (Complex){0, 0}));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_3i(const Vectorc *v1, const Vector3i *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? (Complex){v2->x, 0} : (i == 1 ? (Complex){v2->y, 0} : (i == 2 ? (Complex){v2->z, 0} : (Complex){0, 0})));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_3f(const Vectorc *v1, const Vector3f *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? (Complex){v2->x, 0} : (i == 1 ? (Complex){v2->y, 0} : (i == 2 ? (Complex){v2->z, 0} : (Complex){0, 0})));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_3d(const Vectorc *v1, const Vector3d *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? (Complex){v2->x, 0} : (i == 1 ? (Complex){v2->y, 0} : (i == 2 ? (Complex){v2->z, 0} : (Complex){0, 0})));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_3c(const Vectorc *v1, const Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : (Complex){0, 0})));
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_i(const Vectorc *v1, const Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (v2->len > i ? (Complex){v2->data[i], 0} : (Complex){0, 0});
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_f(const Vectorc *v1, const Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (v2->len > i ? (Complex){v2->data[i], 0} : (Complex){0, 0});
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_d(const Vectorc *v1, const Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = (v1->len >= v2->len ? v1->len : v2->len);
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    for (size_t i = 0; i < res->len; i++)
    {
        Complex a = (v1->len > i ? v1->data[i] : (Complex){0, 0});
        Complex b = (v2->len > i ? (Complex){v2->data[i], 0} : (Complex){0, 0});
        res->data[i] = add_complex(a, b);
    }
    return res;
}

Vectorc *add_vectorc_c(const Vectorc *v1, const Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        return Nonec;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    if (v1->len == v2->len)
    {
        res->len = v1->len;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            res->data[i] = add_complex(v1->data[i], v2->data[i]);
        }
        return 0;
    }
    else
    {
        res->len = v1->len >= v2->len ? v1->len : v2->len;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++)
        {
            Complex a = (v1->len - 1 >= i ? v1->data[i] : (Complex){0, 0});
            Complex b = (v2->len - 1 >= i ? v2->data[i] : (Complex){0, 0});
            res->data[i] = add_complex(a, b);
        }
        return res;
    }
}
