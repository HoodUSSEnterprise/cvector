#ifndef COPY_COMPLEX_H
#define COPY_COMPLEX_H

#include "complex/base_complex.h"

void copy_complex_ptr_ptr(Complex *c1, const Complex *c2);

void copy_complex_ptr_c(Complex *c1, Complex c2);

#define copy_complex(c1, c2) _Generic((c2), \
    Complex *: copy_complex_ptr_ptr,        \
    Complex: copy_complex_ptr_c)(c1, c2)

#endif // COPY_COMPLEX_H