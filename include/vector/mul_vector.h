#ifndef MUL_VECTOR_H
#define MUL_VECTOR_H

#include "vector/base_vector.h"
#include "complex/operator_complex.h"
#include <math.h>

// ============ Vector2i  ============
double mul_vector2i_2i(const Vector2i *v1, const Vector2i *v2);

double mul_vector2i_2f(const Vector2i *v1, const Vector2f *v2);

double mul_vector2i_2d(const Vector2i *v1, const Vector2d *v2);

Complex mul_vector2i_2c(const Vector2i *v1, const Vector2c *v2);

double mul_vector2i_3i(const Vector2i *v1, const Vector3i *v2);

double mul_vector2i_3f(const Vector2i *v1, const Vector3f *v2);

double mul_vector2i_3d(const Vector2i *v1, const Vector3d *v2);

Complex mul_vector2i_3c(const Vector2i *v1, const Vector3c *v2);

double mul_vector2i_i(const Vector2i *v1, const Vectori *v2);

double mul_vector2i_f(const Vector2i *v1, const Vectorf *v2);

double mul_vector2i_d(const Vector2i *v1, const Vectord *v2);

Complex mul_vector2i_c(const Vector2i *v1, const Vectorc *v2);

// ============ Vector2f  ============
double mul_vector2f_2i(const Vector2f *v1, const Vector2i *v2);

double mul_vector2f_2f(const Vector2f *v1, const Vector2f *v2);

double mul_vector2f_2d(const Vector2f *v1, const Vector2d *v2);

Complex mul_vector2f_2c(const Vector2f *v1, const Vector2c *v2);

double mul_vector2f_3i(const Vector2f *v1, const Vector3i *v2);

double mul_vector2f_3f(const Vector2f *v1, const Vector3f *v2);

double mul_vector2f_3d(const Vector2f *v1, const Vector3d *v2);

Complex mul_vector2f_3c(const Vector2f *v1, const Vector3c *v2);

double mul_vector2f_i(const Vector2f *v1, const Vectori *v2);

double mul_vector2f_f(const Vector2f *v1, const Vectorf *v2);

double mul_vector2f_d(const Vector2f *v1, const Vectord *v2);

Complex mul_vector2f_c(const Vector2f *v1, const Vectorc *v2);

// ============ Vector2d  ============
double mul_vector2d_2i(const Vector2d *v1, const Vector2i *v2);

double mul_vector2d_2f(const Vector2d *v1, const Vector2f *v2);

double mul_vector2d_2d(const Vector2d *v1, const Vector2d *v2);

Complex mul_vector2d_2c(const Vector2d *v1, const Vector2c *v2);

double mul_vector2d_3i(const Vector2d *v1, const Vector3i *v2);

double mul_vector2d_3f(const Vector2d *v1, const Vector3f *v2);

double mul_vector2d_3d(const Vector2d *v1, const Vector3d *v2);

Complex mul_vector2d_3c(const Vector2d *v1, const Vector3c *v2);

double mul_vector2d_i(const Vector2d *v1, const Vectori *v2);

double mul_vector2d_f(const Vector2d *v1, const Vectorf *v2);

double mul_vector2d_d(const Vector2d *v1, const Vectord *v2);

Complex mul_vector2d_c(const Vector2d *v1, const Vectorc *v2);

// ============ Vector2c  ============
Complex mul_vector2c_2i(const Vector2c *v1, const Vector2i *v2);

Complex mul_vector2c_2f(const Vector2c *v1, const Vector2f *v2);

Complex mul_vector2c_2d(const Vector2c *v1, const Vector2d *v2);

Complex mul_vector2c_2c(const Vector2c *v1, const Vector2c *v2);

Complex mul_vector2c_3i(const Vector2c *v1, const Vector3i *v2);

Complex mul_vector2c_3f(const Vector2c *v1, const Vector3f *v2);

Complex mul_vector2c_3d(const Vector2c *v1, const Vector3d *v2);

Complex mul_vector2c_3c(const Vector2c *v1, const Vector3c *v2);

Complex mul_vector2c_i(const Vector2c *v1, const Vectori *v2);

Complex mul_vector2c_f(const Vector2c *v1, const Vectorf *v2);

Complex mul_vector2c_d(const Vector2c *v1, const Vectord *v2);

Complex mul_vector2c_c(const Vector2c *v1, const Vectorc *v2);

// ============ Vector3i  ============
double mul_vector3i_2i(const Vector3i *v1, const Vector2i *v2);

double mul_vector3i_2f(const Vector3i *v1, const Vector2f *v2);

double mul_vector3i_2d(const Vector3i *v1, const Vector2d *v2);

Complex mul_vector3i_2c(const Vector3i *v1, const Vector2c *v2);

double mul_vector3i_3i(const Vector3i *v1, const Vector3i *v2);

double mul_vector3i_3f(const Vector3i *v1, const Vector3f *v2);

double mul_vector3i_3d(const Vector3i *v1, const Vector3d *v2);

Complex mul_vector3i_3c(const Vector3i *v1, const Vector3c *v2);

double mul_vector3i_i(const Vector3i *v1, const Vectori *v2);

double mul_vector3i_f(const Vector3i *v1, const Vectorf *v2);

double mul_vector3i_d(const Vector3i *v1, const Vectord *v2);

Complex mul_vector3i_c(const Vector3i *v1, const Vectorc *v2);

// ============ Vector3f  ============
double mul_vector3f_2i(const Vector3f *v1, const Vector2i *v2);

double mul_vector3f_2f(const Vector3f *v1, const Vector2f *v2);

double mul_vector3f_2d(const Vector3f *v1, const Vector2d *v2);

Complex mul_vector3f_2c(const Vector3f *v1, const Vector2c *v2);

double mul_vector3f_3i(const Vector3f *v1, const Vector3i *v2);

double mul_vector3f_3f(const Vector3f *v1, const Vector3f *v2);

double mul_vector3f_3d(const Vector3f *v1, const Vector3d *v2);

Complex mul_vector3f_3c(const Vector3f *v1, const Vector3c *v2);

double mul_vector3f_i(const Vector3f *v1, const Vectori *v2);

double mul_vector3f_f(const Vector3f *v1, const Vectorf *v2);

double mul_vector3f_d(const Vector3f *v1, const Vectord *v2);

Complex mul_vector3f_c(const Vector3f *v1, const Vectorc *v2);

// ============ Vector3d  ============
double mul_vector3d_2i(const Vector3d *v1, const Vector2i *v2);

double mul_vector3d_2f(const Vector3d *v1, const Vector2f *v2);

double mul_vector3d_2d(const Vector3d *v1, const Vector2d *v2);

Complex mul_vector3d_2c(const Vector3d *v1, const Vector2c *v2);

double mul_vector3d_3i(const Vector3d *v1, const Vector3i *v2);

double mul_vector3d_3f(const Vector3d *v1, const Vector3f *v2);

double mul_vector3d_3d(const Vector3d *v1, const Vector3d *v2);

Complex mul_vector3d_3c(const Vector3d *v1, const Vector3c *v2);

double mul_vector3d_i(const Vector3d *v1, const Vectori *v2);

double mul_vector3d_f(const Vector3d *v1, const Vectorf *v2);

double mul_vector3d_d(const Vector3d *v1, const Vectord *v2);

Complex mul_vector3d_c(const Vector3d *v1, const Vectorc *v2);

// ============ Vector3c  ============
Complex mul_vector3c_2i(const Vector3c *v1, const Vector2i *v2);

Complex mul_vector3c_2f(const Vector3c *v1, const Vector2f *v2);

Complex mul_vector3c_2d(const Vector3c *v1, const Vector2d *v2);

Complex mul_vector3c_2c(const Vector3c *v1, const Vector2c *v2);

Complex mul_vector3c_3i(const Vector3c *v1, const Vector3i *v2);

Complex mul_vector3c_3f(const Vector3c *v1, const Vector3f *v2);

Complex mul_vector3c_3d(const Vector3c *v1, const Vector3d *v2);

Complex mul_vector3c_3c(const Vector3c *v1, const Vector3c *v2);

Complex mul_vector3c_i(const Vector3c *v1, const Vectori *v2);

Complex mul_vector3c_f(const Vector3c *v1, const Vectorf *v2);

Complex mul_vector3c_d(const Vector3c *v1, const Vectord *v2);

Complex mul_vector3c_c(const Vector3c *v1, const Vectorc *v2);

// ============ Vectori  ============
double mul_vectori_2i(const Vectori *v1, const Vector2i *v2);

double mul_vectori_2f(const Vectori *v1, const Vector2f *v2);

double mul_vectori_2d(const Vectori *v1, const Vector2d *v2);

Complex mul_vectori_2c(const Vectori *v1, const Vector2c *v2);

double mul_vectori_3i(const Vectori *v1, const Vector3i *v2);

double mul_vectori_3f(const Vectori *v1, const Vector3f *v2);

double mul_vectori_3d(const Vectori *v1, const Vector3d *v2);

Complex mul_vectori_3c(const Vectori *v1, const Vector3c *v2);

double mul_vectori_i(const Vectori *v1, const Vectori *v2);

double mul_vectori_f(const Vectori *v1, const Vectorf *v2);

double mul_vectori_d(const Vectori *v1, const Vectord *v2);

Complex mul_vectori_c(const Vectori *v1, const Vectorc *v2);

// ============ Vectorf  ============
double mul_vectorf_2i(const Vectorf *v1, const Vector2i *v2);

double mul_vectorf_2f(const Vectorf *v1, const Vector2f *v2);

double mul_vectorf_2d(const Vectorf *v1, const Vector2d *v2);

Complex mul_vectorf_2c(const Vectorf *v1, const Vector2c *v2);

double mul_vectorf_3i(const Vectorf *v1, const Vector3i *v2);

double mul_vectorf_3f(const Vectorf *v1, const Vector3f *v2);

double mul_vectorf_3d(const Vectorf *v1, const Vector3d *v2);

Complex mul_vectorf_3c(const Vectorf *v1, const Vector3c *v2);

double mul_vectorf_i(const Vectorf *v1, const Vectori *v2);

double mul_vectorf_f(const Vectorf *v1, const Vectorf *v2);

double mul_vectorf_d(const Vectorf *v1, const Vectord *v2);

Complex mul_vectorf_c(const Vectorf *v1, const Vectorc *v2);

// ============ Vectord  ============
double mul_vectord_2i(const Vectord *v1, const Vector2i *v2);

double mul_vectord_2f(const Vectord *v1, const Vector2f *v2);

double mul_vectord_2d(const Vectord *v1, const Vector2d *v2);

Complex mul_vectord_2c(const Vectord *v1, const Vector2c *v2);

double mul_vectord_3i(const Vectord *v1, const Vector3i *v2);

double mul_vectord_3f(const Vectord *v1, const Vector3f *v2);

double mul_vectord_3d(const Vectord *v1, const Vector3d *v2);

Complex mul_vectord_3c(const Vectord *v1, const Vector3c *v2);

double mul_vectord_i(const Vectord *v1, const Vectori *v2);

double mul_vectord_f(const Vectord *v1, const Vectorf *v2);

double mul_vectord_d(const Vectord *v1, const Vectord *v2);

Complex mul_vectord_c(const Vectord *v1, const Vectorc *v2);

// ============ Vectorc  ============
Complex mul_vectorc_2i(const Vectorc *v1, const Vector2i *v2);

Complex mul_vectorc_2f(const Vectorc *v1, const Vector2f *v2);

Complex mul_vectorc_2d(const Vectorc *v1, const Vector2d *v2);

Complex mul_vectorc_2c(const Vectorc *v1, const Vector2c *v2);

Complex mul_vectorc_3i(const Vectorc *v1, const Vector3i *v2);

Complex mul_vectorc_3f(const Vectorc *v1, const Vector3f *v2);

Complex mul_vectorc_3d(const Vectorc *v1, const Vector3d *v2);

Complex mul_vectorc_3c(const Vectorc *v1, const Vector3c *v2);

Complex mul_vectorc_i(const Vectorc *v1, const Vectori *v2);

Complex mul_vectorc_f(const Vectorc *v1, const Vectorf *v2);

Complex mul_vectorc_d(const Vectorc *v1, const Vectord *v2);

Complex mul_vectorc_c(const Vectorc *v1, const Vectorc *v2);

// 乘法宏（逐分量相乘，返回标量）
#define mul_vec(v1, v2) _Generic((v1), \
    Vectorc *: _Generic((v2),          \
        Vectorc *: mul_vectorc_c,      \
        Vectord *: mul_vectorc_d,      \
        Vectorf *: mul_vectorc_f,      \
        Vectori *: mul_vectorc_i,      \
        Vector3c *: mul_vectorc_3c,    \
        Vector3d *: mul_vectorc_3d,    \
        Vector3f *: mul_vectorc_3f,    \
        Vector3i *: mul_vectorc_3i,    \
        Vector2c *: mul_vectorc_2c,    \
        Vector2d *: mul_vectorc_2d,    \
        Vector2f *: mul_vectorc_2f,    \
        Vector2i *: mul_vectorc_2i),   \
    Vectord *: _Generic((v2),          \
        Vectorc *: mul_vectord_c,      \
        Vectord *: mul_vectord_d,      \
        Vectorf *: mul_vectord_f,      \
        Vectori *: mul_vectord_i,      \
        Vector3c *: mul_vectord_3c,    \
        Vector3d *: mul_vectord_3d,    \
        Vector3f *: mul_vectord_3f,    \
        Vector3i *: mul_vectord_3i,    \
        Vector2c *: mul_vectord_2c,    \
        Vector2d *: mul_vectord_2d,    \
        Vector2f *: mul_vectord_2f,    \
        Vector2i *: mul_vectord_2i),   \
    Vectorf *: _Generic((v2),          \
        Vectorc *: mul_vectorf_c,      \
        Vectord *: mul_vectorf_d,      \
        Vectorf *: mul_vectorf_f,      \
        Vectori *: mul_vectorf_i,      \
        Vector3c *: mul_vectorf_3c,    \
        Vector3d *: mul_vectorf_3d,    \
        Vector3f *: mul_vectorf_3f,    \
        Vector3i *: mul_vectorf_3i,    \
        Vector2c *: mul_vectorf_2c,    \
        Vector2d *: mul_vectorf_2d,    \
        Vector2f *: mul_vectorf_2f,    \
        Vector2i *: mul_vectorf_2i),   \
    Vectori *: _Generic((v2),          \
        Vectorc *: mul_vectori_c,      \
        Vectord *: mul_vectori_d,      \
        Vectorf *: mul_vectori_f,      \
        Vectori *: mul_vectori_i,      \
        Vector3c *: mul_vectori_3c,    \
        Vector3d *: mul_vectori_3d,    \
        Vector3f *: mul_vectori_3f,    \
        Vector3i *: mul_vectori_3i,    \
        Vector2c *: mul_vectori_2c,    \
        Vector2d *: mul_vectori_2d,    \
        Vector2f *: mul_vectori_2f,    \
        Vector2i *: mul_vectori_2i),   \
    Vector3c *: _Generic((v2),         \
        Vectorc *: mul_vector3c_c,     \
        Vectord *: mul_vector3c_d,     \
        Vectorf *: mul_vector3c_f,     \
        Vectori *: mul_vector3c_i,     \
        Vector3c *: mul_vector3c_3c,   \
        Vector3d *: mul_vector3c_3d,   \
        Vector3f *: mul_vector3c_3f,   \
        Vector3i *: mul_vector3c_3i,   \
        Vector2c *: mul_vector3c_2c,   \
        Vector2d *: mul_vector3c_2d,   \
        Vector2f *: mul_vector3c_2f,   \
        Vector2i *: mul_vector3c_2i),  \
    Vector3d *: _Generic((v2),         \
        Vectorc *: mul_vector3d_c,     \
        Vectord *: mul_vector3d_d,     \
        Vectorf *: mul_vector3d_f,     \
        Vectori *: mul_vector3d_i,     \
        Vector3c *: mul_vector3d_3c,   \
        Vector3d *: mul_vector3d_3d,   \
        Vector3f *: mul_vector3d_3f,   \
        Vector3i *: mul_vector3d_3i,   \
        Vector2c *: mul_vector3d_2c,   \
        Vector2d *: mul_vector3d_2d,   \
        Vector2f *: mul_vector3d_2f,   \
        Vector2i *: mul_vector3d_2i),  \
    Vector3f *: _Generic((v2),         \
        Vectorc *: mul_vector3f_c,     \
        Vectord *: mul_vector3f_d,     \
        Vectorf *: mul_vector3f_f,     \
        Vectori *: mul_vector3f_i,     \
        Vector3c *: mul_vector3f_3c,   \
        Vector3d *: mul_vector3f_3d,   \
        Vector3f *: mul_vector3f_3f,   \
        Vector3i *: mul_vector3f_3i,   \
        Vector2c *: mul_vector3f_2c,   \
        Vector2d *: mul_vector3f_2d,   \
        Vector2f *: mul_vector3f_2f,   \
        Vector2i *: mul_vector3f_2i),  \
    Vector3i *: _Generic((v2),         \
        Vectorc *: mul_vector3i_c,     \
        Vectord *: mul_vector3i_d,     \
        Vectorf *: mul_vector3i_f,     \
        Vectori *: mul_vector3i_i,     \
        Vector3c *: mul_vector3i_3c,   \
        Vector3d *: mul_vector3i_3d,   \
        Vector3f *: mul_vector3i_3f,   \
        Vector3i *: mul_vector3i_3i,   \
        Vector2c *: mul_vector3i_2c,   \
        Vector2d *: mul_vector3i_2d,   \
        Vector2f *: mul_vector3i_2f,   \
        Vector2i *: mul_vector3i_2i),  \
    Vector2c *: _Generic((v2),         \
        Vectorc *: mul_vector2c_c,     \
        Vectord *: mul_vector2c_d,     \
        Vectorf *: mul_vector2c_f,     \
        Vectori *: mul_vector2c_i,     \
        Vector3c *: mul_vector2c_3c,   \
        Vector3d *: mul_vector2c_3d,   \
        Vector3f *: mul_vector2c_3f,   \
        Vector3i *: mul_vector2c_3i,   \
        Vector2c *: mul_vector2c_2c,   \
        Vector2d *: mul_vector2c_2d,   \
        Vector2f *: mul_vector2c_2f,   \
        Vector2i *: mul_vector2c_2i),  \
    Vector2d *: _Generic((v2),         \
        Vectorc *: mul_vector2d_c,     \
        Vectord *: mul_vector2d_d,     \
        Vectorf *: mul_vector2d_f,     \
        Vectori *: mul_vector2d_i,     \
        Vector3c *: mul_vector2d_3c,   \
        Vector3d *: mul_vector2d_3d,   \
        Vector3f *: mul_vector2d_3f,   \
        Vector3i *: mul_vector2d_3i,   \
        Vector2c *: mul_vector2d_2c,   \
        Vector2d *: mul_vector2d_2d,   \
        Vector2f *: mul_vector2d_2f,   \
        Vector2i *: mul_vector2d_2i),  \
    Vector2f *: _Generic((v2),         \
        Vectorc *: mul_vector2f_c,     \
        Vectord *: mul_vector2f_d,     \
        Vectorf *: mul_vector2f_f,     \
        Vectori *: mul_vector2f_i,     \
        Vector3c *: mul_vector2f_3c,   \
        Vector3d *: mul_vector2f_3d,   \
        Vector3f *: mul_vector2f_3f,   \
        Vector3i *: mul_vector2f_3i,   \
        Vector2c *: mul_vector2f_2c,   \
        Vector2d *: mul_vector2f_2d,   \
        Vector2f *: mul_vector2f_2f,   \
        Vector2i *: mul_vector2f_2i),  \
    Vector2i *: _Generic((v2),         \
        Vectorc *: mul_vector2i_c,     \
        Vectord *: mul_vector2i_d,     \
        Vectorf *: mul_vector2i_f,     \
        Vectori *: mul_vector2i_i,     \
        Vector3c *: mul_vector2i_3c,   \
        Vector3d *: mul_vector2i_3d,   \
        Vector3f *: mul_vector2i_3f,   \
        Vector3i *: mul_vector2i_3i,   \
        Vector2c *: mul_vector2i_2c,   \
        Vector2d *: mul_vector2i_2d,   \
        Vector2f *: mul_vector2i_2f,   \
        Vector2i *: mul_vector2i_2i))(v1, v2)

#endif // MUL_VECTOR_H