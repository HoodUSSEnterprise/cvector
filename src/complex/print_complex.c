#include "complex/print_complex.h"

void print_complex(Complex c)
{
    printf("(%lf, %lfi)\n", c.real, c.imag);
}