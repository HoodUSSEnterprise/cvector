#include "complex/copy_complex.h"

void copy_complex_ptr_ptr(Complex *c1, Complex *c2)
{
    memcpy(c1, c2, sizeof(Complex));
}

void copy_complex_ptr_c(Complex *c1, Complex c2)
{
    c1->imag = c2.imag;
    c1->real = c2.real;
}

void copy_complex_c_ptr(Complex c1, Complex *c2)
{
    c1.imag = c2->imag;
    c1.real = c2->real;
}

void copy_complex_c_c(Complex c1, Complex c2)
{
    c1.imag = c2.imag;
    c1.real = c2.real;
}