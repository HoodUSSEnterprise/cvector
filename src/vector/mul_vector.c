#include "vector/mul_vector.h"

double mul_vector2i_2i(const Vector2i *v1, const Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_2f(const Vector2i *v1, const Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_2d(const Vector2i *v1, const Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2i_2c(const Vector2i *v1, const Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2i_3i(const Vector2i *v1, const Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_3f(const Vector2i *v1, const Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2i_3d(const Vector2i *v1, const Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2i_3c(const Vector2i *v1, const Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2i_i(const Vector2i *v1, const Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2i_f(const Vector2i *v1, const Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2i_d(const Vector2i *v1, const Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

Complex mul_vector2i_c(const Vector2i *v1, const Vectorc *v2)
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
double mul_vector2f_2i(const Vector2f *v1, const Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_2f(const Vector2f *v1, const Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_2d(const Vector2f *v1, const Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2f_2c(const Vector2f *v1, const Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2f_3i(const Vector2f *v1, const Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_3f(const Vector2f *v1, const Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2f_3d(const Vector2f *v1, const Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2f_3c(const Vector2f *v1, const Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2f_i(const Vector2f *v1, const Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2f_f(const Vector2f *v1, const Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2f_d(const Vector2f *v1, const Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

Complex mul_vector2f_c(const Vector2f *v1, const Vectorc *v2)
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
double mul_vector2d_2i(const Vector2d *v1, const Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_2f(const Vector2d *v1, const Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_2d(const Vector2d *v1, const Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2d_2c(const Vector2d *v1, const Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2d_3i(const Vector2d *v1, const Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_3f(const Vector2d *v1, const Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector2d_3d(const Vector2d *v1, const Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector2d_3c(const Vector2d *v1, const Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector2d_i(const Vector2d *v1, const Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2d_f(const Vector2d *v1, const Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

double mul_vector2d_d(const Vector2d *v1, const Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    return sum;
}

Complex mul_vector2d_c(const Vector2d *v1, const Vectorc *v2)
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
Complex mul_vector2c_2i(const Vector2c *v1, const Vector2i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_2f(const Vector2c *v1, const Vector2f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_2d(const Vector2c *v1, const Vector2d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_2c(const Vector2c *v1, const Vector2c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3i(const Vector2c *v1, const Vector3i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3f(const Vector2c *v1, const Vector3f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3d(const Vector2c *v1, const Vector3d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector2c_3c(const Vector2c *v1, const Vector3c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    return add_complex(r1, r2);
}

Complex mul_vector2c_i(const Vector2c *v1, const Vectori *v2)
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

Complex mul_vector2c_f(const Vector2c *v1, const Vectorf *v2)
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

Complex mul_vector2c_d(const Vector2c *v1, const Vectord *v2)
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

Complex mul_vector2c_c(const Vector2c *v1, const Vectorc *v2)
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
double mul_vector3i_2i(const Vector3i *v1, const Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3i_2f(const Vector3i *v1, const Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3i_2d(const Vector3i *v1, const Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector3i_2c(const Vector3i *v1, const Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector3i_3i(const Vector3i *v1, const Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3i_3f(const Vector3i *v1, const Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3i_3d(const Vector3i *v1, const Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Complex mul_vector3i_3c(const Vector3i *v1, const Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    Complex r3 = mul_complex(c3, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

double mul_vector3i_i(const Vector3i *v1, const Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3i_f(const Vector3i *v1, const Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3i_d(const Vector3i *v1, const Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

Complex mul_vector3i_c(const Vector3i *v1, const Vectorc *v2)
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
double mul_vector3f_2i(const Vector3f *v1, const Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3f_2f(const Vector3f *v1, const Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3f_2d(const Vector3f *v1, const Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector3f_2c(const Vector3f *v1, const Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector3f_3i(const Vector3f *v1, const Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3f_3f(const Vector3f *v1, const Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3f_3d(const Vector3f *v1, const Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Complex mul_vector3f_3c(const Vector3f *v1, const Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    Complex r3 = mul_complex(c3, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

double mul_vector3f_i(const Vector3f *v1, const Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3f_f(const Vector3f *v1, const Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3f_d(const Vector3f *v1, const Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

Complex mul_vector3f_c(const Vector3f *v1, const Vectorc *v2)
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
double mul_vector3d_2i(const Vector3d *v1, const Vector2i *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3d_2f(const Vector3d *v1, const Vector2f *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

double mul_vector3d_2d(const Vector3d *v1, const Vector2d *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

Complex mul_vector3d_2c(const Vector3d *v1, const Vector2c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    return add_complex(r1, r2);
}

double mul_vector3d_3i(const Vector3d *v1, const Vector3i *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3d_3f(const Vector3d *v1, const Vector3f *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double mul_vector3d_3d(const Vector3d *v1, const Vector3d *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Complex mul_vector3d_3c(const Vector3d *v1, const Vector3c *v2)
{
    Complex c1 = {v1->x, 0};
    Complex c2 = {v1->y, 0};
    Complex c3 = {v1->z, 0};
    Complex r1 = mul_complex(c1, v2->x);
    Complex r2 = mul_complex(c2, v2->y);
    Complex r3 = mul_complex(c3, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

double mul_vector3d_i(const Vector3d *v1, const Vectori *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3d_f(const Vector3d *v1, const Vectorf *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

double mul_vector3d_d(const Vector3d *v1, const Vectord *v2)
{
    double sum = 0;
    sum += v1->x * (v2->len > 0 ? v2->data[0] : 0);
    sum += v1->y * (v2->len > 1 ? v2->data[1] : 0);
    sum += v1->z * (v2->len > 2 ? v2->data[2] : 0);
    return sum;
}

Complex mul_vector3d_c(const Vector3d *v1, const Vectorc *v2)
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
Complex mul_vector3c_2i(const Vector3c *v1, const Vector2i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector3c_2f(const Vector3c *v1, const Vector2f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector3c_2d(const Vector3c *v1, const Vector2d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    return add_complex(r1, r2);
}

Complex mul_vector3c_2c(const Vector3c *v1, const Vector2c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    return add_complex(r1, r2);
}

Complex mul_vector3c_3i(const Vector3c *v1, const Vector3i *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    Complex r3 = mul_complex(v1->z, c3);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_3f(const Vector3c *v1, const Vector3f *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    Complex r3 = mul_complex(v1->z, c3);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_3d(const Vector3c *v1, const Vector3d *v2)
{
    Complex c1 = {v2->x, 0};
    Complex c2 = {v2->y, 0};
    Complex c3 = {v2->z, 0};
    Complex r1 = mul_complex(v1->x, c1);
    Complex r2 = mul_complex(v1->y, c2);
    Complex r3 = mul_complex(v1->z, c3);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_3c(const Vector3c *v1, const Vector3c *v2)
{
    Complex r1 = mul_complex(v1->x, v2->x);
    Complex r2 = mul_complex(v1->y, v2->y);
    Complex r3 = mul_complex(v1->z, v2->z);
    return add_complex(add_complex(r1, r2), r3);
}

Complex mul_vector3c_i(const Vector3c *v1, const Vectori *v2)
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

Complex mul_vector3c_f(const Vector3c *v1, const Vectorf *v2)
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

Complex mul_vector3c_d(const Vector3c *v1, const Vectord *v2)
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

Complex mul_vector3c_c(const Vector3c *v1, const Vectorc *v2)
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
double mul_vectori_2i(const Vectori *v1, const Vector2i *v2)
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

double mul_vectori_2f(const Vectori *v1, const Vector2f *v2)
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

double mul_vectori_2d(const Vectori *v1, const Vector2d *v2)
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

Complex mul_vectori_2c(const Vectori *v1, const Vector2c *v2)
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

double mul_vectori_3i(const Vectori *v1, const Vector3i *v2)
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

double mul_vectori_3f(const Vectori *v1, const Vector3f *v2)
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

double mul_vectori_3d(const Vectori *v1, const Vector3d *v2)
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

Complex mul_vectori_3c(const Vectori *v1, const Vector3c *v2)
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

double mul_vectori_i(const Vectori *v1, const Vectori *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectori_f(const Vectori *v1, const Vectorf *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectori_d(const Vectori *v1, const Vectord *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

Complex mul_vectori_c(const Vectori *v1, const Vectorc *v2)
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
double mul_vectorf_2i(const Vectorf *v1, const Vector2i *v2)
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

double mul_vectorf_2f(const Vectorf *v1, const Vector2f *v2)
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

double mul_vectorf_2d(const Vectorf *v1, const Vector2d *v2)
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

Complex mul_vectorf_2c(const Vectorf *v1, const Vector2c *v2)
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

double mul_vectorf_3i(const Vectorf *v1, const Vector3i *v2)
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

double mul_vectorf_3f(const Vectorf *v1, const Vector3f *v2)
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

double mul_vectorf_3d(const Vectorf *v1, const Vector3d *v2)
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

Complex mul_vectorf_3c(const Vectorf *v1, const Vector3c *v2)
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

double mul_vectorf_i(const Vectorf *v1, const Vectori *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectorf_f(const Vectorf *v1, const Vectorf *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectorf_d(const Vectorf *v1, const Vectord *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

Complex mul_vectorf_c(const Vectorf *v1, const Vectorc *v2)
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
double mul_vectord_2i(const Vectord *v1, const Vector2i *v2)
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

double mul_vectord_2f(const Vectord *v1, const Vector2f *v2)
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

double mul_vectord_2d(const Vectord *v1, const Vector2d *v2)
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

Complex mul_vectord_2c(const Vectord *v1, const Vector2c *v2)
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

double mul_vectord_3i(const Vectord *v1, const Vector3i *v2)
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

double mul_vectord_3f(const Vectord *v1, const Vector3f *v2)
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

double mul_vectord_3d(const Vectord *v1, const Vector3d *v2)
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

Complex mul_vectord_3c(const Vectord *v1, const Vector3c *v2)
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

double mul_vectord_i(const Vectord *v1, const Vectori *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectord_f(const Vectord *v1, const Vectorf *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

double mul_vectord_d(const Vectord *v1, const Vectord *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    double sum = 0;
    for (size_t i = 0; i < min_len; i++)
    {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}

Complex mul_vectord_c(const Vectord *v1, const Vectorc *v2)
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
Complex mul_vectorc_2i(const Vectorc *v1, const Vector2i *v2)
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

Complex mul_vectorc_2f(const Vectorc *v1, const Vector2f *v2)
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

Complex mul_vectorc_2d(const Vectorc *v1, const Vector2d *v2)
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

Complex mul_vectorc_2c(const Vectorc *v1, const Vector2c *v2)
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

Complex mul_vectorc_3i(const Vectorc *v1, const Vector3i *v2)
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

Complex mul_vectorc_3f(const Vectorc *v1, const Vector3f *v2)
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

Complex mul_vectorc_3d(const Vectorc *v1, const Vector3d *v2)
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

Complex mul_vectorc_3c(const Vectorc *v1, const Vector3c *v2)
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

Complex mul_vectorc_i(const Vectorc *v1, const Vectori *v2)
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

Complex mul_vectorc_f(const Vectorc *v1, const Vectorf *v2)
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

Complex mul_vectorc_d(const Vectorc *v1, const Vectord *v2)
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

Complex mul_vectorc_c(const Vectorc *v1, const Vectorc *v2)
{
    size_t min_len = v1->len < v2->len ? v1->len : v2->len;
    Complex sum = {0, 0};
    for (size_t i = 0; i < min_len; i++)
    {
        sum = add_complex(sum, mul_complex(v1->data[i], v2->data[i]));
    }
    return sum;
}