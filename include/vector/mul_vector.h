#ifndef MUL_VECTOR_H
#define MUL_VECTOR_H

#include "vector/base_vector.h"
#include "complex/operator_complex.h"
#include <math.h>

// ============ Vector2i  ============
double mul_vector2i_2i(Vector2i *v1, Vector2i *v2);

double mul_vector2i_2f(Vector2i *v1, Vector2f *v2);

double mul_vector2i_2d(Vector2i *v1, Vector2d *v2);

Complex mul_vector2i_2c(Vector2i *v1, Vector2c *v2);

double mul_vector2i_3i(Vector2i *v1, Vector3i *v2);

double mul_vector2i_3f(Vector2i *v1, Vector3f *v2);

double mul_vector2i_3d(Vector2i *v1, Vector3d *v2);

Complex mul_vector2i_3c(Vector2i *v1, Vector3c *v2);

double mul_vector2i_i(Vector2i *v1, Vectori *v2);

double mul_vector2i_f(Vector2i *v1, Vectorf *v2);

double mul_vector2i_d(Vector2i *v1, Vectord *v2);

Complex mul_vector2i_c(Vector2i *v1, Vectorc *v2);

// ============ Vector2f  ============
double mul_vector2f_2i(Vector2f *v1, Vector2i *v2);

double mul_vector2f_2f(Vector2f *v1, Vector2f *v2);

double mul_vector2f_2d(Vector2f *v1, Vector2d *v2);

Complex mul_vector2f_2c(Vector2f *v1, Vector2c *v2);

double mul_vector2f_3i(Vector2f *v1, Vector3i *v2);

double mul_vector2f_3f(Vector2f *v1, Vector3f *v2);

double mul_vector2f_3d(Vector2f *v1, Vector3d *v2);

Complex mul_vector2f_3c(Vector2f *v1, Vector3c *v2);

double mul_vector2f_i(Vector2f *v1, Vectori *v2);

double mul_vector2f_f(Vector2f *v1, Vectorf *v2);

double mul_vector2f_d(Vector2f *v1, Vectord *v2);

Complex mul_vector2f_c(Vector2f *v1, Vectorc *v2);

// ============ Vector2d  ============
double mul_vector2d_2i(Vector2d *v1, Vector2i *v2);

double mul_vector2d_2f(Vector2d *v1, Vector2f *v2);

double mul_vector2d_2d(Vector2d *v1, Vector2d *v2);

Complex mul_vector2d_2c(Vector2d *v1, Vector2c *v2);

double mul_vector2d_3i(Vector2d *v1, Vector3i *v2);

double mul_vector2d_3f(Vector2d *v1, Vector3f *v2);

double mul_vector2d_3d(Vector2d *v1, Vector3d *v2);

Complex mul_vector2d_3c(Vector2d *v1, Vector3c *v2);

double mul_vector2d_i(Vector2d *v1, Vectori *v2);

double mul_vector2d_f(Vector2d *v1, Vectorf *v2);

double mul_vector2d_d(Vector2d *v1, Vectord *v2);

Complex mul_vector2d_c(Vector2d *v1, Vectorc *v2);

// ============ Vector2c  ============
Complex mul_vector2c_2i(Vector2c *v1, Vector2i *v2);

Complex mul_vector2c_2f(Vector2c *v1, Vector2f *v2);

Complex mul_vector2c_2d(Vector2c *v1, Vector2d *v2);

Complex mul_vector2c_2c(Vector2c *v1, Vector2c *v2);

Complex mul_vector2c_3i(Vector2c *v1, Vector3i *v2);

Complex mul_vector2c_3f(Vector2c *v1, Vector3f *v2);

Complex mul_vector2c_3d(Vector2c *v1, Vector3d *v2);

Complex mul_vector2c_3c(Vector2c *v1, Vector3c *v2);

Complex mul_vector2c_i(Vector2c *v1, Vectori *v2);

Complex mul_vector2c_f(Vector2c *v1, Vectorf *v2);

Complex mul_vector2c_d(Vector2c *v1, Vectord *v2);

Complex mul_vector2c_c(Vector2c *v1, Vectorc *v2);

// ============ Vector3i  ============
double mul_vector3i_2i(Vector3i *v1, Vector2i *v2);

double mul_vector3i_2f(Vector3i *v1, Vector2f *v2);

double mul_vector3i_2d(Vector3i *v1, Vector2d *v2);

Complex mul_vector3i_2c(Vector3i *v1, Vector2c *v2);

double mul_vector3i_3i(Vector3i *v1, Vector3i *v2);

double mul_vector3i_3f(Vector3i *v1, Vector3f *v2);

double mul_vector3i_3d(Vector3i *v1, Vector3d *v2);

Complex mul_vector3i_3c(Vector3i *v1, Vector3c *v2);

double mul_vector3i_i(Vector3i *v1, Vectori *v2);

double mul_vector3i_f(Vector3i *v1, Vectorf *v2);

double mul_vector3i_d(Vector3i *v1, Vectord *v2);

Complex mul_vector3i_c(Vector3i *v1, Vectorc *v2);

// ============ Vector3f  ============
double mul_vector3f_2i(Vector3f *v1, Vector2i *v2);

double mul_vector3f_2f(Vector3f *v1, Vector2f *v2);

double mul_vector3f_2d(Vector3f *v1, Vector2d *v2);

Complex mul_vector3f_2c(Vector3f *v1, Vector2c *v2);

double mul_vector3f_3i(Vector3f *v1, Vector3i *v2);

double mul_vector3f_3f(Vector3f *v1, Vector3f *v2);

double mul_vector3f_3d(Vector3f *v1, Vector3d *v2);

Complex mul_vector3f_3c(Vector3f *v1, Vector3c *v2);

double mul_vector3f_i(Vector3f *v1, Vectori *v2);

double mul_vector3f_f(Vector3f *v1, Vectorf *v2);

double mul_vector3f_d(Vector3f *v1, Vectord *v2);

Complex mul_vector3f_c(Vector3f *v1, Vectorc *v2);

// ============ Vector3d  ============
double mul_vector3d_2i(Vector3d *v1, Vector2i *v2);

double mul_vector3d_2f(Vector3d *v1, Vector2f *v2);

double mul_vector3d_2d(Vector3d *v1, Vector2d *v2);

Complex mul_vector3d_2c(Vector3d *v1, Vector2c *v2);

double mul_vector3d_3i(Vector3d *v1, Vector3i *v2);

double mul_vector3d_3f(Vector3d *v1, Vector3f *v2);

double mul_vector3d_3d(Vector3d *v1, Vector3d *v2);

Complex mul_vector3d_3c(Vector3d *v1, Vector3c *v2);

double mul_vector3d_i(Vector3d *v1, Vectori *v2);

double mul_vector3d_f(Vector3d *v1, Vectorf *v2);

double mul_vector3d_d(Vector3d *v1, Vectord *v2);

Complex mul_vector3d_c(Vector3d *v1, Vectorc *v2);

// ============ Vector3c  ============
Complex mul_vector3c_2i(Vector3c *v1, Vector2i *v2);

Complex mul_vector3c_2f(Vector3c *v1, Vector2f *v2);

Complex mul_vector3c_2d(Vector3c *v1, Vector2d *v2);

Complex mul_vector3c_2c(Vector3c *v1, Vector2c *v2);

Complex mul_vector3c_3i(Vector3c *v1, Vector3i *v2);

Complex mul_vector3c_3f(Vector3c *v1, Vector3f *v2);

Complex mul_vector3c_3d(Vector3c *v1, Vector3d *v2);

Complex mul_vector3c_3c(Vector3c *v1, Vector3c *v2);

Complex mul_vector3c_i(Vector3c *v1, Vectori *v2);

Complex mul_vector3c_f(Vector3c *v1, Vectorf *v2);

Complex mul_vector3c_d(Vector3c *v1, Vectord *v2);

Complex mul_vector3c_c(Vector3c *v1, Vectorc *v2);

// ============ Vectori  ============
double mul_vectori_2i(Vectori *v1, Vector2i *v2);

double mul_vectori_2f(Vectori *v1, Vector2f *v2);

double mul_vectori_2d(Vectori *v1, Vector2d *v2);

Complex mul_vectori_2c(Vectori *v1, Vector2c *v2);

double mul_vectori_3i(Vectori *v1, Vector3i *v2);

double mul_vectori_3f(Vectori *v1, Vector3f *v2);

double mul_vectori_3d(Vectori *v1, Vector3d *v2);

Complex mul_vectori_3c(Vectori *v1, Vector3c *v2);

double mul_vectori_i(Vectori *v1, Vectori *v2);

double mul_vectori_f(Vectori *v1, Vectorf *v2);

double mul_vectori_d(Vectori *v1, Vectord *v2);

Complex mul_vectori_c(Vectori *v1, Vectorc *v2);

// ============ Vectorf  ============
double mul_vectorf_2i(Vectorf *v1, Vector2i *v2);

double mul_vectorf_2f(Vectorf *v1, Vector2f *v2);

double mul_vectorf_2d(Vectorf *v1, Vector2d *v2);

Complex mul_vectorf_2c(Vectorf *v1, Vector2c *v2);

double mul_vectorf_3i(Vectorf *v1, Vector3i *v2);

double mul_vectorf_3f(Vectorf *v1, Vector3f *v2);

double mul_vectorf_3d(Vectorf *v1, Vector3d *v2);

Complex mul_vectorf_3c(Vectorf *v1, Vector3c *v2);

double mul_vectorf_i(Vectorf *v1, Vectori *v2);

double mul_vectorf_f(Vectorf *v1, Vectorf *v2);

double mul_vectorf_d(Vectorf *v1, Vectord *v2);

Complex mul_vectorf_c(Vectorf *v1, Vectorc *v2);

// ============ Vectord  ============
double mul_vectord_2i(Vectord *v1, Vector2i *v2);

double mul_vectord_2f(Vectord *v1, Vector2f *v2);

double mul_vectord_2d(Vectord *v1, Vector2d *v2);

Complex mul_vectord_2c(Vectord *v1, Vector2c *v2);

double mul_vectord_3i(Vectord *v1, Vector3i *v2);

double mul_vectord_3f(Vectord *v1, Vector3f *v2);

double mul_vectord_3d(Vectord *v1, Vector3d *v2);

Complex mul_vectord_3c(Vectord *v1, Vector3c *v2);

double mul_vectord_i(Vectord *v1, Vectori *v2);

double mul_vectord_f(Vectord *v1, Vectorf *v2);

double mul_vectord_d(Vectord *v1, Vectord *v2);

Complex mul_vectord_c(Vectord *v1, Vectorc *v2);

// ============ Vectorc  ============
Complex mul_vectorc_2i(Vectorc *v1, Vector2i *v2);

Complex mul_vectorc_2f(Vectorc *v1, Vector2f *v2);

Complex mul_vectorc_2d(Vectorc *v1, Vector2d *v2);

Complex mul_vectorc_2c(Vectorc *v1, Vector2c *v2);

Complex mul_vectorc_3i(Vectorc *v1, Vector3i *v2);

Complex mul_vectorc_3f(Vectorc *v1, Vector3f *v2);

Complex mul_vectorc_3d(Vectorc *v1, Vector3d *v2);

Complex mul_vectorc_3c(Vectorc *v1, Vector3c *v2);

Complex mul_vectorc_i(Vectorc *v1, Vectori *v2);

Complex mul_vectorc_f(Vectorc *v1, Vectorf *v2);

Complex mul_vectorc_d(Vectorc *v1, Vectord *v2);

Complex mul_vectorc_c(Vectorc *v1, Vectorc *v2);

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