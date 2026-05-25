#include "vector/mul_vector.h"

double mul_vector2i_2i(Vector2i *v1, Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_2f(Vector2i *v1, Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_2d(Vector2i *v1, Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2i_2c(Vector2i *v1, Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2i_3i(Vector2i *v1, Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_3f(Vector2i *v1, Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_3d(Vector2i *v1, Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2i_3c(Vector2i *v1, Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2i_i(Vector2i *v1, Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2i_f(Vector2i *v1, Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2i_d(Vector2i *v1, Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

Complex mul_vector2i_c(Vector2i *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->data[1]));
    }
    return sum;
}

// ============ Vector2f  ============
double mul_vector2f_2i(Vector2f *v1, Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_2f(Vector2f *v1, Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_2d(Vector2f *v1, Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2f_2c(Vector2f *v1, Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2f_3i(Vector2f *v1, Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_3f(Vector2f *v1, Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_3d(Vector2f *v1, Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2f_3c(Vector2f *v1, Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2f_i(Vector2f *v1, Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2f_f(Vector2f *v1, Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2f_d(Vector2f *v1, Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

Complex mul_vector2f_c(Vector2f *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->data[1]));
    }
    return sum;
}

// ============ Vector2d  ============
double mul_vector2d_2i(Vector2d *v1, Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_2f(Vector2d *v1, Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_2d(Vector2d *v1, Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2d_2c(Vector2d *v1, Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2d_3i(Vector2d *v1, Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_3f(Vector2d *v1, Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_3d(Vector2d *v1, Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2d_3c(Vector2d *v1, Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2d_i(Vector2d *v1, Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2d_f(Vector2d *v1, Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2d_d(Vector2d *v1, Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

Complex mul_vector2d_c(Vector2d *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->data[1]));
    }
    return sum;
}

// ============ Vector2c  ============
Complex mul_vector2c_2i(Vector2c *v1, Vector2i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_2f(Vector2c *v1, Vector2f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_2d(Vector2c *v1, Vector2d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_2c(Vector2c *v1, Vector2c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3i(Vector2c *v1, Vector3i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3f(Vector2c *v1, Vector3f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3d(Vector2c *v1, Vector3d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3c(Vector2c *v1, Vector3c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    return add_complex(r1, r2);
}

Complex mul_vector2c_i(Vector2c *v1, Vectori *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->len > 0 ? v2->data[0] : 0, 0};
    Complex c2 = {v2->len > 1 ? v2->data[1] : 0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, c1));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, c2));
    }
    return sum;
}

Complex mul_vector2c_f(Vector2c *v1, Vectorf *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->len > 0 ? v2->data[0] : 0, 0};
    Complex c2 = {v2->len > 1 ? v2->data[1] : 0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, c1));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, c2));
    }
    return sum;
}

Complex mul_vector2c_d(Vector2c *v1, Vectord *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->len > 0 ? v2->data[0] : 0, 0};
    Complex c2 = {v2->len > 1 ? v2->data[1] : 0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, c1));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, c2));
    }
    return sum;
}

Complex mul_vector2c_c(Vector2c *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, v2->data[1]));
    }
    return sum;
}

// ============ Vector3i  ============
double mul_vector3i_2i(Vector3i *v1, Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3i_2f(Vector3i *v1, Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3i_2d(Vector3i *v1, Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector3i_2c(Vector3i *v1, Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector3i_3i(Vector3i *v1, Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3i_3f(Vector3i *v1, Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3i_3d(Vector3i *v1, Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Complex mul_vector3i_3c(Vector3i *v1, Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    Complex r3 = mul_complex(c3, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

double mul_vector3i_i(Vector3i *v1, Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3i_f(Vector3i *v1, Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3i_d(Vector3i *v1, Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

Complex mul_vector3i_c(Vector3i *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->data[1]));
    }
    if (v2->len > 2)
    {
        sum = add_complex(sum, mul_complex(c3, v2->data[2]));
    }
    return sum;
}

// ============ Vector3f  ============
double mul_vector3f_2i(Vector3f *v1, Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3f_2f(Vector3f *v1, Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3f_2d(Vector3f *v1, Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector3f_2c(Vector3f *v1, Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector3f_3i(Vector3f *v1, Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3f_3f(Vector3f *v1, Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3f_3d(Vector3f *v1, Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Complex mul_vector3f_3c(Vector3f *v1, Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    Complex r3 = mul_complex(c3, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

double mul_vector3f_i(Vector3f *v1, Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3f_f(Vector3f *v1, Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3f_d(Vector3f *v1, Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

Complex mul_vector3f_c(Vector3f *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->data[1]));
    }
    if (v2->len > 2)
    {
        sum = add_complex(sum, mul_complex(c3, v2->data[2]));
    }
    return sum;
}

// ============ Vector3d  ============
double mul_vector3d_2i(Vector3d *v1, Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3d_2f(Vector3d *v1, Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3d_2d(Vector3d *v1, Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector3d_2c(Vector3d *v1, Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector3d_3i(Vector3d *v1, Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3d_3f(Vector3d *v1, Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3d_3d(Vector3d *v1, Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Complex mul_vector3d_3c(Vector3d *v1, Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    Complex r3 = mul_complex(c3, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

double mul_vector3d_i(Vector3d *v1, Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3d_f(Vector3d *v1, Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3d_d(Vector3d *v1, Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

Complex mul_vector3d_c(Vector3d *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->data[1]));
    }
    if (v2->len > 2)
    {
        sum = add_complex(sum, mul_complex(c3, v2->data[2]));
    }
    return sum;
}

// ============ Vector3c  ============
Complex mul_vector3c_2i(Vector3c *v1, Vector2i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector3c_2f(Vector3c *v1, Vector2f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector3c_2d(Vector3c *v1, Vector2d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector3c_2c(Vector3c *v1, Vector2c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    return add_complex(r1, r2);
}

Complex mul_vector3c_3i(Vector3c *v1, Vector3i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    Complex r3 = mul_complex(v1->z, c3);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_3f(Vector3c *v1, Vector3f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    Complex r3 = mul_complex(v1->z, c3);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_3d(Vector3c *v1, Vector3d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    Complex r3 = mul_complex(v1->z, c3);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_3c(Vector3c *v1, Vector3c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    Complex r3 = mul_complex(v1->z, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_i(Vector3c *v1, Vectori *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->len > 0 ? v2->data[0] : 0, 0};
    Complex c2 = {v2->len > 1 ? v2->data[1] : 0, 0};
    Complex c3 = {v2->len > 2 ? v2->data[2] : 0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, c1));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, c2));
    }
    if (v2->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->z, c3));
    }
    return sum;
}

Complex mul_vector3c_f(Vector3c *v1, Vectorf *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->len > 0 ? v2->data[0] : 0, 0};
    Complex c2 = {v2->len > 1 ? v2->data[1] : 0, 0};
    Complex c3 = {v2->len > 2 ? v2->data[2] : 0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, c1));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, c2));
    }
    if (v2->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->z, c3));
    }
    return sum;
}

Complex mul_vector3c_d(Vector3c *v1, Vectord *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->len > 0 ? v2->data[0] : 0, 0};
    Complex c2 = {v2->len > 1 ? v2->data[1] : 0, 0};
    Complex c3 = {v2->len > 2 ? v2->data[2] : 0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, c1));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, c2));
    }
    if (v2->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->z, c3));
    }
    return sum;
}

Complex mul_vector3c_c(Vector3c *v1, Vectorc *v2)
{
    Complex sum = {0, 0};
    if (v2->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->x, v2->data[0]));
    }
    if (v2->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->y, v2->data[1]));
    }
    if (v2->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->z, v2->data[2]));
    }
    return sum;
}

// ============ Vectori  ============
double mul_vectori_2i(Vectori *v1, Vector2i *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

double mul_vectori_2f(Vectori *v1, Vector2f *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

double mul_vectori_2d(Vectori *v1, Vector2d *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

Complex mul_vectori_2c(Vectori *v1, Vector2c *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->len > 0 ? v1->data[0] : 0, 0};
    Complex c2 = {v1->len > 1 ? v1->data[1] : 0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->y));
    }
    return sum;
}

double mul_vectori_3i(Vectori *v1, Vector3i *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

double mul_vectori_3f(Vectori *v1, Vector3f *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

double mul_vectori_3d(Vectori *v1, Vector3d *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

Complex mul_vectori_3c(Vectori *v1, Vector3c *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->len > 0 ? v1->data[0] : 0, 0};
    Complex c2 = {v1->len > 1 ? v1->data[1] : 0, 0};
    Complex c3 = {v1->len > 2 ? v1->data[2] : 0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->y));
    }
    if (v1->len > 2)
    {
        sum = add_complex(sum, mul_complex(c3, v2->z));
    }
    return sum;
}

double mul_vectori_i(Vectori *v1, Vectori *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectori_f(Vectori *v1, Vectorf *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectori_d(Vectori *v1, Vectord *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

Complex mul_vectori_c(Vectori *v1, Vectorc *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        Complex c = {v1->data[i], 0};
        sum = add_complex(sum, mul_complex(c, v2->data[i]));
    }
    return sum;
}

// ============ Vectorf  ============
double mul_vectorf_2i(Vectorf *v1, Vector2i *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

double mul_vectorf_2f(Vectorf *v1, Vector2f *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

double mul_vectorf_2d(Vectorf *v1, Vector2d *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

Complex mul_vectorf_2c(Vectorf *v1, Vector2c *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->len > 0 ? v1->data[0] : 0, 0};
    Complex c2 = {v1->len > 1 ? v1->data[1] : 0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->y));
    }
    return sum;
}

double mul_vectorf_3i(Vectorf *v1, Vector3i *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

double mul_vectorf_3f(Vectorf *v1, Vector3f *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

double mul_vectorf_3d(Vectorf *v1, Vector3d *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

Complex mul_vectorf_3c(Vectorf *v1, Vector3c *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->len > 0 ? v1->data[0] : 0, 0};
    Complex c2 = {v1->len > 1 ? v1->data[1] : 0, 0};
    Complex c3 = {v1->len > 2 ? v1->data[2] : 0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->y));
    }
    if (v1->len > 2)
    {
        sum = add_complex(sum, mul_complex(c3, v2->z));
    }
    return sum;
}

double mul_vectorf_i(Vectorf *v1, Vectori *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectorf_f(Vectorf *v1, Vectorf *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectorf_d(Vectorf *v1, Vectord *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

Complex mul_vectorf_c(Vectorf *v1, Vectorc *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        Complex c = {v1->data[i], 0};
        sum = add_complex(sum, mul_complex(c, v2->data[i]));
    }
    return sum;
}

// ============ Vectord  ============
double mul_vectord_2i(Vectord *v1, Vector2i *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

double mul_vectord_2f(Vectord *v1, Vector2f *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

double mul_vectord_2d(Vectord *v1, Vector2d *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    return sum;
}

Complex mul_vectord_2c(Vectord *v1, Vector2c *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->len > 0 ? v1->data[0] : 0, 0};
    Complex c2 = {v1->len > 1 ? v1->data[1] : 0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->y));
    }
    return sum;
}

double mul_vectord_3i(Vectord *v1, Vector3i *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

double mul_vectord_3f(Vectord *v1, Vector3f *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

double mul_vectord_3d(Vectord *v1, Vector3d *v2)
{
    double sum = 0;
    if (v1->len > 0)
    {
        sum += v1->data[0] * v2->x;
    }
    if (v1->len > 1)
    {
        sum += v1->data[1] * v2->y;
    }
    if (v1->len > 2)
    {
        sum += v1->data[2] * v2->z;
    }
    return sum;
}

Complex mul_vectord_3c(Vectord *v1, Vector3c *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v1->len > 0 ? v1->data[0] : 0, 0};
    Complex c2 = {v1->len > 1 ? v1->data[1] : 0, 0};
    Complex c3 = {v1->len > 2 ? v1->data[2] : 0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(c1, v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(c2, v2->y));
    }
    if (v1->len > 2)
    {
        sum = add_complex(sum, mul_complex(c3, v2->z));
    }
    return sum;
}

double mul_vectord_i(Vectord *v1, Vectori *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectord_f(Vectord *v1, Vectorf *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectord_d(Vectord *v1, Vectord *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

Complex mul_vectord_c(Vectord *v1, Vectorc *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        Complex c = {v1->data[i], 0};
        sum = add_complex(sum, mul_complex(c, v2->data[i]));
    }
    return sum;
}

// ============ Vectorc  ============
Complex mul_vectorc_2i(Vectorc *v1, Vector2i *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], c1));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], c2));
    }
    return sum;
}

Complex mul_vectorc_2f(Vectorc *v1, Vector2f *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], c1));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], c2));
    }
    return sum;
}

Complex mul_vectorc_2d(Vectorc *v1, Vector2d *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], c1));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], c2));
    }
    return sum;
}

Complex mul_vectorc_2c(Vectorc *v1, Vector2c *v2)
{
    Complex sum = {0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], v2->y));
    }
    return sum;
}

Complex mul_vectorc_3i(Vectorc *v1, Vector3i *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], c1));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], c2));
    }
    if (v1->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->data[2], c3));
    }
    return sum;
}

Complex mul_vectorc_3f(Vectorc *v1, Vector3f *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], c1));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], c2));
    }
    if (v1->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->data[2], c3));
    }
    return sum;
}

Complex mul_vectorc_3d(Vectorc *v1, Vector3d *v2)
{
    Complex sum = {0, 0};
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], c1));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], c2));
    }
    if (v1->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->data[2], c3));
    }
    return sum;
}

Complex mul_vectorc_3c(Vectorc *v1, Vector3c *v2)
{
    Complex sum = {0, 0};
    if (v1->len > 0)
    {
        sum = add_complex(sum, mul_complex(v1->data[0], v2->x));
    }
    if (v1->len > 1)
    {
        sum = add_complex(sum, mul_complex(v1->data[1], v2->y));
    }
    if (v1->len > 2)
    {
        sum = add_complex(sum, mul_complex(v1->data[2], v2->z));
    }
    return sum;
}

Complex mul_vectorc_i(Vectorc *v1, Vectori *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        Complex c = {v2->data[i], 0};
        sum = add_complex(sum, mul_complex(v1->data[i], c));
    }
    return sum;
}

Complex mul_vectorc_f(Vectorc *v1, Vectorf *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        Complex c = {v2->data[i], 0};
        sum = add_complex(sum, mul_complex(v1->data[i], c));
    }
    return sum;
}

Complex mul_vectorc_d(Vectorc *v1, Vectord *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        Complex c = {v2->data[i], 0};
        sum = add_complex(sum, mul_complex(v1->data[i], c));
    }
    return sum;
}

Complex mul_vectorc_c(Vectorc *v1, Vectorc *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        sum = add_complex(sum, mul_complex(v1->data[i], v2->data[i]));
    }
    return sum;
}