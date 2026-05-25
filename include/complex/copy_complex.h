#ifndef COPY_COMPLEX_H
#define COPY_COMPLEX_H

#include "complex/base_complex.h"

void copy_complex_ptr_ptr(Complex *c1, Complex *c2);

void copy_complex_ptr_c(Complex *c1, Complex c2);

void copy_complex_c_ptr(Complex c1, Complex *c2);

void copy_complex_c_c(Complex c1, Complex c2);

#define copy_complex(x, y) _Generic((x), \
    Complex *: _Generic((y),             \
        Complex *: copy_complex_ptr_ptr, \
        Complex: copy_complex_ptr_c),    \
    Complex: _Generic((y),               \
        Complex *: copy_complex_c_ptr,   \
        Complex: copy_complex_c_c))(x, y)

#endif // COPY_COMPLEX_H