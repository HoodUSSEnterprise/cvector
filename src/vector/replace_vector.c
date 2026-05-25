#include "vector/replace_vector.h"

Vector2i *replace_vector2i_elem(Vector2i *v, int old_elem, int new_elem)
{
    if (find_vector2i(v, old_elem) == -1)
    {
        printf("no value : %d \n", old_elem);
        return v;
    }
    else
    {
        Vector2i *res = create_vector2i(v->x, v->y);
        if (res->x == old_elem)
        {
            res->x = new_elem;
        }
        if (res->y == old_elem)
        {
            res->y = new_elem;
        }
        return res;
    }
}

Vector2f *replace_vector2f_elem(Vector2f *v, float old_elem, float new_elem)
{
    if (find_vector2f(v, old_elem) == -1)
    {
        printf("no value : %f \n", old_elem);
        return v;
    }
    else
    {
        Vector2f *res = create_vector2f(v->x, v->y);
        if (fabs(res->x - old_elem) < 1e-6)
        {
            res->x = new_elem;
        }
        if (fabs(res->y - old_elem) < 1e-6)
        {
            res->y = new_elem;
        }
        return res;
    }
}

Vector2d *replace_vector2d_elem(Vector2d *v, double old_elem, double new_elem)
{
    if (find_vector2d(v, old_elem) == -1)
    {
        printf("no value : %lf \n", old_elem);
        return v;
    }
    else
    {
        Vector2d *res = create_vector2d(v->x, v->y);
        if (fabs(res->x - old_elem) < 1e-6)
        {
            res->x = new_elem;
        }
        if (fabs(res->y - old_elem) < 1e-6)
        {
            res->y = new_elem;
        }
        return res;
    }
}

Vector2c *replace_vector2c_elem(Vector2c *v, Complex old_elem, Complex new_elem)
{
    if (find_vector2c(v, old_elem) == -1)
    {
        printf("no value : ");
        print_complex(old_elem);
        return v;
    }
    else
    {
        Vector2c *res = create_vector2c(v->x, v->y);
        if (is_equal_complex(res->x, old_elem))
        {
            res->x = new_elem;
        }
        if (is_equal_complex(res->y, old_elem))
        {
            res->y = new_elem;
        }
        return res;
    }
}

Vector3i *replace_vector3i_elem(Vector3i *v, int old_elem, int new_elem)
{
    if (find_vector3i(v, old_elem) == -1)
    {
        printf("no value : %d \n", old_elem);
        return v;
    }
    else
    {
        Vector3i *res = create_vector3i(v->x, v->y, v->z);
        if (res->x == old_elem)
        {
            res->x = new_elem;
        }
        if (res->y == old_elem)
        {
            res->y = new_elem;
        }
        if (res->z == old_elem)
        {
            res->z = new_elem;
        }
        return res;
    }
}

Vector3f *replace_vector3f_elem(Vector3f *v, float old_elem, float new_elem)
{
    if (find_vector3f(v, old_elem) == -1)
    {
        printf("no value : %f \n", old_elem);
        return v;
    }
    else
    {
        Vector3f *res = create_vector3f(v->x, v->y, v->z);
        if (fabs(res->x - old_elem) < 1e-6)
        {
            res->x = new_elem;
        }
        if (fabs(res->y - old_elem) < 1e-6)
        {
            res->y = new_elem;
        }
        if (fabs(res->z - old_elem) < 1e-6)
        {
            res->z = new_elem;
        }
        return res;
    }
}

Vector3d *replace_vector3d_elem(Vector3d *v, double old_elem, double new_elem)
{
    if (find_vector3d(v, old_elem) == -1)
    {
        printf("no value : %lf \n", old_elem);
        return v;
    }
    else
    {
        Vector3d *res = create_vector3d(v->x, v->y, v->z);
        if (fabs(res->x - old_elem) < 1e-6)
        {
            res->x = new_elem;
        }
        if (fabs(res->y - old_elem) < 1e-6)
        {
            res->y = new_elem;
        }
        if (fabs(res->z - old_elem) < 1e-6)
        {
            res->z = new_elem;
        }
        return res;
    }
}

Vector3c *replace_vector3c_elem(Vector3c *v, Complex old_elem, Complex new_elem)
{
    if (find_vector3c(v, old_elem) == -1)
    {
        printf("no value : ");
        print_complex(old_elem);
        return v;
    }
    else
    {
        Vector3c *res = create_vector3c(v->x, v->y, v->z);
        if (is_equal_complex(res->x, old_elem))
        {
            res->x = new_elem;
        }
        if (is_equal_complex(res->y, old_elem))
        {
            res->y = new_elem;
        }
        if (is_equal_complex(res->z, old_elem))
        {
            res->z = new_elem;
        }
        return res;
    }
}

Vectori *replace_vectori_elem(Vectori *v, int old_elem, int new_elem)
{
    if (find_vectori(v, old_elem) == -1)
    {
        printf("no value : %d \n", old_elem);
        return v;
    }
    else
    {
        Vectori *res = create_vectori(v->len, v->data);
        res->len = v->len;
        for (size_t i = 0; i < v->len; i++)
        {
            if (v->data[i] == old_elem)
            {
                res->data[i] = new_elem;
            }
            else
            {
                res->data[i] = v->data[i];
            }
        }
        return res;
    }
}

Vectorf *replace_vectorf_elem(Vectorf *v, float old_elem, float new_elem)
{
    if (find_vectorf(v, old_elem) == -1)
    {
        printf("no value : %f \n", old_elem);
        return v;
    }
    else
    {
        Vectorf *res = create_vectorf(v->len, v->data);
        res->len = v->len;
        for (size_t i = 0; i < v->len; i++)
        {
            if (fabs(v->data[i] - old_elem) < 1e-6)
            {
                res->data[i] = new_elem;
            }
            else
            {
                res->data[i] = v->data[i];
            }
        }
        return res;
    }
}

Vectord *replace_vectord_elem(Vectord *v, double old_elem, double new_elem)
{
    if (find_vectord(v, old_elem) == -1)
    {
        printf("no value : %lf \n", old_elem);
        return v;
    }
    else
    {
        Vectord *res = create_vectord(v->len, v->data);
        res->len = v->len;
        for (size_t i = 0; i < v->len; i++)
        {
            if (fabs(v->data[i] - old_elem) < 1e-6)
            {
                res->data[i] = new_elem;
            }
            else
            {
                res->data[i] = v->data[i];
            }
        }
        return res;
    }
}

Vectorc *replace_vectorc_elem(Vectorc *v, Complex old_elem, Complex new_elem)
{
    if (find_vectorc(v, old_elem) == -1)
    {
        printf("no value : ");
        print_complex(old_elem);
        return v;
    }
    else
    {
        Vectorc *res = create_vectorc(v->len, v->data);
        res->len = v->len;
        for (size_t i = 0; i < v->len; i++)
        {
            if (is_equal_complex(v->data[i], old_elem))
            {
                res->data[i] = new_elem;
            }
            else
            {
                res->data[i] = v->data[i];
            }
        }
        return res;
    }
}

Vectori *replace_vectori_array(Vectori *v, int *old_array, int *new_array, size_t len)
{
    if (v->len < len)
    {
        return v;
    }
    else
    {
        Vectori *res = (Vectori *)malloc(sizeof(Vectori));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = v->len;
        res->data = (int *)malloc(sizeof(int) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        memcpy(res->data, v->data, sizeof(int) * res->len);
        for (size_t i = 0; i < res->len; i++) // 数组从前往后遍历，如果出现需要替换的，就直接换掉，否则不需要，因为就需要换一次
        {
            for (size_t j = 0; j < len; j++)
            {
                if (res->data[i] == old_array[j])
                {
                    DEBUG_LOG("%d, %d", old_array[j], new_array[j]);
                    res->data[i] = new_array[j];
                    break;
                }
            }
        }
        return res;
    }
}

Vectorf *replace_vectorf_array(Vectorf *v, float *old_array, float *new_array, size_t len)
{
    if (v->len < len)
    {
        return v;
    }
    else
    {
        Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = v->len;
        res->data = (float *)malloc(sizeof(float) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        memcpy(res->data, v->data, sizeof(float) * res->len);
        for (size_t i = 0; i < res->len; i++) // 数组从前往后遍历，如果出现需要替换的，就直接换掉，否则不需要，因为就需要换一次
        {
            for (size_t j = 0; j < len; j++)
            {
                if (fabs(res->data[i] - old_array[j]) < 1e-6)
                {
                    res->data[i] = new_array[j];
                    break;
                }
            }
        }
        return res;
    }
}

Vectord *replace_vectord_array(Vectord *v, double *old_array, double *new_array, size_t len)
{
    if (v->len < len)
    {
        return v;
    }
    else
    {
        Vectord *res = (Vectord *)malloc(sizeof(Vectord));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = v->len;
        res->data = (double *)malloc(sizeof(double) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        memcpy(res->data, v->data, sizeof(double) * res->len);
        for (size_t i = 0; i < res->len; i++) // 数组从前往后遍历，如果出现需要替换的，就直接换掉，否则不需要，因为就需要换一次
        {
            for (size_t j = 0; j < len; j++)
            {
                if (fabs(res->data[i] - old_array[j]) < 1e-6)
                {
                    res->data[i] = new_array[j];
                    break;
                }
            }
        }
        return res;
    }
}

Vectorc *replace_vectorc_array(Vectorc *v, Complex *old_array, Complex *new_array, size_t len)
{
    if (v->len < len)
    {
        return v;
    }
    else
    {
        Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
        if (res == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        res->len = v->len;
        res->data = (Complex *)malloc(sizeof(Complex) * res->len);
        if (res->data == NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        memcpy(res->data, v->data, sizeof(Complex) * res->len);
        for (size_t i = 0; i < res->len; i++) // 数组从前往后遍历，如果出现需要替换的，就直接换掉，否则不需要，因为就需要换一次
        {
            for (size_t j = 0; j < len; j++)
            {
                if (is_equal_complex(res->data[i], old_array[j]))
                {
                    res->data[i] = new_array[j];
                    break;
                }
            }
        }
        return res;
    }
}
