#include "vector/operator_vector.h"
#include <limits.h>
#define INFTY INT_MAX

static int data_infty[1] = {INFTY};
static Vectori nonei_point = {1, data_infty};
static Vectorf nonef_point = {1, (float *)data_infty};
static Vectord noned_point = {1, (double *)data_infty};
static Vectorc nonec_point = {1, (Complex *)data_infty};
Vectori *Nonei = &nonei_point;
Vectorf *Nonef = &nonef_point;
Vectord *Noned = &noned_point;
Vectorc *Nonec = &nonec_point;

//TODO There are some bug in pointer transform. I'll modify them right away.
// ============ Vector2i  ============
Vector2i *add_vector2i_2i(Vector2i *v1, Vector2i *v2)
{
    Vector2i *res = (Vector2i *)malloc(sizeof(Vector2i));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2f *add_vector2i_2f(Vector2i *v1, Vector2f *v2)
{
    Vector2f *res = (Vector2f *)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2i_2d(Vector2i *v1, Vector2d *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2c *add_vector2i_2c(Vector2i *v1, Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    return res;
}

Vector3i *add_vector2i_3i(Vector2i *v1, Vector3i *v2)
{
    Vector3i *res = (Vector3i *)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3f *add_vector2i_3f(Vector2i *v1, Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2i_3d(Vector2i *v1, Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3c *add_vector2i_3c(Vector2i *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = v2->z;
    return res;
}

Vectori *add_vector2i_i(Vector2i *v1, Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectori *res = (Vectori *)malloc(sizeof(Vectori));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 2;
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
        }
        res->len = (v2->len >= 2 ? v2->len : 2);
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
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

Vectorf *add_vector2i_f(Vector2i *v1, Vectorf *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector2i_d(Vector2i *v1, Vectord *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector2i_c(Vector2i *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vector2f *add_vector2f_2i(Vector2f *v1, Vector2i *v2)
{
    Vector2f *res = (Vector2f *)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2f *add_vector2f_2f(Vector2f *v1, Vector2f *v2)
{
    Vector2f *res = (Vector2f *)malloc(sizeof(Vector2f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2f_2d(Vector2f *v1, Vector2d *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2c *add_vector2f_2c(Vector2f *v1, Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    return res;
}

Vector3f *add_vector2f_3i(Vector2f *v1, Vector3i *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3f *add_vector2f_3f(Vector2f *v1, Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2f_3d(Vector2f *v1, Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3c *add_vector2f_3c(Vector2f *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = v2->z;
    return res;
}

Vectorf *add_vector2f_i(Vector2f *v1, Vectori *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectorf *add_vector2f_f(Vector2f *v1, Vectorf *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector2f_d(Vector2f *v1, Vectord *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector2f_c(Vector2f *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vector2d *add_vector2d_2i(Vector2d *v1, Vector2i *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2d_2f(Vector2d *v1, Vector2f *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2d *add_vector2d_2d(Vector2d *v1, Vector2d *v2)
{
    Vector2d *res = (Vector2d *)malloc(sizeof(Vector2d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    return res;
}

Vector2c *add_vector2d_2c(Vector2d *v1, Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    return res;
}

Vector3d *add_vector2d_3i(Vector2d *v1, Vector3i *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2d_3f(Vector2d *v1, Vector3f *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3d *add_vector2d_3d(Vector2d *v1, Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v2->z;
    return res;
}

Vector3c *add_vector2d_3c(Vector2d *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = v2->z;
    return res;
}

Vectord *add_vector2d_i(Vector2d *v1, Vectori *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector2d_f(Vector2d *v1, Vectorf *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector2d_d(Vector2d *v1, Vectord *v2)
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector2d_c(Vector2d *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vector2c *add_vector2c_2i(Vector2c *v1, Vector2i *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    return res;
}

Vector2c *add_vector2c_2f(Vector2c *v1, Vector2f *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    return res;
}

Vector2c *add_vector2c_2d(Vector2c *v1, Vector2d *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    return res;
}

Vector2c *add_vector2c_2c(Vector2c *v1, Vector2c *v2)
{
    Vector2c *res = (Vector2c *)malloc(sizeof(Vector2c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    return res;
}

Vector3c *add_vector2c_3i(Vector2c *v1, Vector3i *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = (Complex){v2->z, 0};
    return res;
}

Vector3c *add_vector2c_3f(Vector2c *v1, Vector3f *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = (Complex){v2->z, 0};
    return res;
}

Vector3c *add_vector2c_3d(Vector2c *v1, Vector3d *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = (Complex){v2->z, 0};
    return res;
}

Vector3c *add_vector2c_3c(Vector2c *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    res->z = v2->z;
    return res;
}

Vectorc *add_vector2c_i(Vector2c *v1, Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector2c_f(Vector2c *v1, Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector2c_d(Vector2c *v1, Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector2c_c(Vector2c *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vector3i *add_vector3i_2i(Vector3i *v1, Vector2i *v2)
{
    Vector3i *res = (Vector3i *)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3f *add_vector3i_2f(Vector3i *v1, Vector2f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3i_2d(Vector3i *v1, Vector2d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3i_2c(Vector3i *v1, Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = (Complex){v1->z, 0};
    return res;
}

Vector3i *add_vector3i_3i(Vector3i *v1, Vector3i *v2)
{
    Vector3i *res = (Vector3i *)malloc(sizeof(Vector3i));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3f *add_vector3i_3f(Vector3i *v1, Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3i_3d(Vector3i *v1, Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3c *add_vector3i_3c(Vector3i *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = add_complex((Complex){v1->z, 0}, v2->z);
    return res;
}

Vectori *add_vector3i_i(Vector3i *v1, Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectori *res = (Vectori *)malloc(sizeof(Vectori));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
        }
        res->len = (v2->len >= 3 ? v2->len : 3);
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
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

Vectorf *add_vector3i_f(Vector3i *v1, Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector3i_d(Vector3i *v1, Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector3i_c(Vector3i *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vector3f *add_vector3f_2i(Vector3f *v1, Vector2i *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3f *add_vector3f_2f(Vector3f *v1, Vector2f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3f_2d(Vector3f *v1, Vector2d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3f_2c(Vector3f *v1, Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = (Complex){v1->z, 0};
    return res;
}

Vector3f *add_vector3f_3i(Vector3f *v1, Vector3i *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3f *add_vector3f_3f(Vector3f *v1, Vector3f *v2)
{
    Vector3f *res = (Vector3f *)malloc(sizeof(Vector3f));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3f_3d(Vector3f *v1, Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3c *add_vector3f_3c(Vector3f *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = add_complex((Complex){v1->z, 0}, v2->z);
    return res;
}

Vectorf *add_vector3f_i(Vector3f *v1, Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorf *add_vector3f_f(Vector3f *v1, Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector3f_d(Vector3f *v1, Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector3f_c(Vector3f *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vector3d *add_vector3d_2i(Vector3d *v1, Vector2i *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3d_2f(Vector3d *v1, Vector2f *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3d *add_vector3d_2d(Vector3d *v1, Vector2d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3d_2c(Vector3d *v1, Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = (Complex){v1->z, 0};
    return res;
}

Vector3d *add_vector3d_3i(Vector3d *v1, Vector3i *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3d_3f(Vector3d *v1, Vector3f *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3d *add_vector3d_3d(Vector3d *v1, Vector3d *v2)
{
    Vector3d *res = (Vector3d *)malloc(sizeof(Vector3d));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    return res;
}

Vector3c *add_vector3d_3c(Vector3d *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex((Complex){v1->x, 0}, v2->x);
    res->y = add_complex((Complex){v1->y, 0}, v2->y);
    res->z = add_complex((Complex){v1->z, 0}, v2->z);
    return res;
}

Vectord *add_vector3d_i(Vector3d *v1, Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector3d_f(Vector3d *v1, Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectord *add_vector3d_d(Vector3d *v1, Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector3d_c(Vector3d *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vector3c *add_vector3c_2i(Vector3c *v1, Vector2i *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_2f(Vector3c *v1, Vector2f *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_2d(Vector3c *v1, Vector2d *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_2c(Vector3c *v1, Vector2c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    res->z = v1->z;
    return res;
}

Vector3c *add_vector3c_3i(Vector3c *v1, Vector3i *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = add_complex(v1->z, (Complex){v2->z, 0});
    return res;
}

Vector3c *add_vector3c_3f(Vector3c *v1, Vector3f *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = add_complex(v1->z, (Complex){v2->z, 0});
    return res;
}

Vector3c *add_vector3c_3d(Vector3c *v1, Vector3d *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, (Complex){v2->x, 0});
    res->y = add_complex(v1->y, (Complex){v2->y, 0});
    res->z = add_complex(v1->z, (Complex){v2->z, 0});
    return res;
}

Vector3c *add_vector3c_3c(Vector3c *v1, Vector3c *v2)
{
    Vector3c *res = (Vector3c *)malloc(sizeof(Vector3c));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->x = add_complex(v1->x, v2->x);
    res->y = add_complex(v1->y, v2->y);
    res->z = add_complex(v1->z, v2->z);
    return res;
}

Vectorc *add_vector3c_i(Vector3c *v1, Vectori *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector3c_f(Vector3c *v1, Vectorf *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector3c_d(Vector3c *v1, Vectord *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorc *add_vector3c_c(Vector3c *v1, Vectorc *v2)
{
    if (v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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
Vectori *add_vectori_2i(Vectori *v1, Vector2i *v2)
{
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = (v1->len >= 2 ? v1->len : 2);
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    for (size_t i = 0; i < res->len; i++)
    {
        int a = (v1->len > i ? v1->data[i] : 0);
        int b = (i == 0 ? v2->x : (i == 1 ? v2->y : 0));
        res->data[i] = a + b;
    }
    return res;
}

Vectorf *add_vectori_2f(Vectori *v1, Vector2f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectori_2d(Vectori *v1, Vector2d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectori_2c(Vectori *v1, Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectori *add_vectori_3i(Vectori *v1, Vector3i *v2)
{
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = (v1->len >= 3 ? v1->len : 3);
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    for (size_t i = 0; i < res->len; i++)
    {
        int a = (v1->len > i ? v1->data[i] : 0);
        int b = (i == 0 ? v2->x : (i == 1 ? v2->y : (i == 2 ? v2->z : 0)));
        res->data[i] = a + b;
    }
    return res;
}

Vectorf *add_vectori_3f(Vectori *v1, Vector3f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectori_3d(Vectori *v1, Vector3d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectori_3c(Vectori *v1, Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectori *add_vectori_i(Vectori *v1, Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        return Nonei;
    }
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    if (v1->len == v2->len)
    {
        res->len = v1->len;
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
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
            printf("No memory\n");
            exit(0);
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

Vectorf *add_vectori_f(Vectori *v1, Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectori_d(Vectori *v1, Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectori_c(Vectori *v1, Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        return Nonec;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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
Vectorf *add_vectorf_2i(Vectorf *v1, Vector2i *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorf *add_vectorf_2f(Vectorf *v1, Vector2f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectorf_2d(Vectorf *v1, Vector2d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorf_2c(Vectorf *v1, Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorf *add_vectorf_3i(Vectorf *v1, Vector3i *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorf *add_vectorf_3f(Vectorf *v1, Vector3f *v2)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectorf_3d(Vectorf *v1, Vector3d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorf_3c(Vectorf *v1, Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorf *add_vectorf_i(Vectorf *v1, Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorf *add_vectorf_f(Vectorf *v1, Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectorf_d(Vectorf *v1, Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorf_c(Vectorf *v1, Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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
Vectord *add_vectord_2i(Vectord *v1, Vector2i *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_2f(Vectord *v1, Vector2f *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_2d(Vectord *v1, Vector2d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectord_2c(Vectord *v1, Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_3i(Vectord *v1, Vector3i *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_3f(Vectord *v1, Vector3f *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_3d(Vectord *v1, Vector3d *v2)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectord_3c(Vectord *v1, Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_i(Vectord *v1, Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_f(Vectord *v1, Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectord *add_vectord_d(Vectord *v1, Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectord_c(Vectord *v1, Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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
Vectorc *add_vectorc_2i(Vectorc *v1, Vector2i *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_2f(Vectorc *v1, Vector2f *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_2d(Vectorc *v1, Vector2d *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_2c(Vectorc *v1, Vector2c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_3i(Vectorc *v1, Vector3i *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_3f(Vectorc *v1, Vector3f *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_3d(Vectorc *v1, Vector3d *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_3c(Vectorc *v1, Vector3c *v2)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_i(Vectorc *v1, Vectori *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_f(Vectorc *v1, Vectorf *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_d(Vectorc *v1, Vectord *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = 0;
        res->data = NULL;
        return res;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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

Vectorc *add_vectorc_c(Vectorc *v1, Vectorc *v2)
{
    if (v1->len == 0 && v2->len == 0)
    {
        return Nonec;
    }
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
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
