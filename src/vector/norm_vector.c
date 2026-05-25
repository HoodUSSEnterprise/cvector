#include "vector/norm_vector.h"

double None = LLONG_MAX;

double norm_vector2i(Vector2i *v, double norm)
{
    double powx = pow(v->x, 1.0 / norm);
    double powy = pow(v->y, 1.0 / norm);
    return pow(powx + powy, 1.0 / norm);
}

double norm_vector2f(Vector2f *v, double norm)
{
    double powx = pow(v->x, 1.0 / norm);
    double powy = pow(v->y, 1.0 / norm);
    return pow(powx + powy, 1.0 / norm);
}

double norm_vector2d(Vector2d *v, double norm)
{
    double powx = pow(v->x, 1.0 / norm);
    double powy = pow(v->y, 1.0 / norm);
    return pow(powx + powy, 1.0 / norm);
}

double norm_vector2c(Vector2c *v, double norm)
{
    double powx = pow(modulus_complex(v->x), 1.0/norm);
    DEBUG_LOG("%lf\n", powx);
    double powy = pow(modulus_complex(v->y), 1.0/norm);
    DEBUG_LOG("%lf\n", powy);
    return pow(powx + powy, 1.0 / norm);
}

double norm_vector3i(Vector3i *v, double norm)
{
    double powx = pow(v->x, 1.0 / norm);
    double powy = pow(v->y, 1.0 / norm);
    double powz = pow(v->y, 1.0 / norm);
    return pow(powx + powy + powz, 1.0 / norm);
}

double norm_vector3f(Vector3f *v, double norm)
{
    double powx = pow(v->x, 1.0 / norm);
    double powy = pow(v->y, 1.0 / norm);
    double powz = pow(v->y, 1.0 / norm);
    return pow(powx + powy + powz, 1.0 / norm);
}

double norm_vector3d(Vector3d *v, double norm)
{
    double powx = pow(v->x, 1.0 / norm);
    double powy = pow(v->y, 1.0 / norm);
    double powz = pow(v->y, 1.0 / norm);
    return pow(powx + powy + powz, 1.0 / norm);
}

double norm_vector3c(Vector3c *v, double norm)
{
    double powx = pow(modulus_complex(v->x), 1.0/norm);
    double powy = pow(modulus_complex(v->y), 1.0/norm);
    double powz = pow(modulus_complex(v->z), 1.0/norm);
    return pow(powx + powy + powz, 1.0 / norm);
}

double norm_vectori(Vectori *v, double norm)
{
    if(v->len == 0)
    {
        return None;
    }
    double sum = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        sum += pow(v->data[i], 1.0 / norm);
    }
    return pow(sum, 1.0 / norm);
}

double norm_vectorf(Vectorf *v, double norm)
{
    if(v->len == 0)
    {
        return None;
    }
    double sum = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        sum += pow(v->data[i], 1.0 / norm);
    }
    return pow(sum, 1.0 / norm);
}

double norm_vectord(Vectord *v, double norm)
{
    if(v->len == 0)
    {
        return None;
    }
    double sum = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        sum += pow(v->data[i], 1.0 / norm);
    }
    return pow(sum, 1.0 / norm);
}

double norm_vectorc(Vectorc *v, double norm)
{
    if(v->len == 0)
    {
        return None;
    }
    double sum = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        sum += pow(modulus_complex(v->data[i]), 1.0 / norm);
    }
    return pow(sum, 1.0 / norm);
}
