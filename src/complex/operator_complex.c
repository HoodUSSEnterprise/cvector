#include "complex/operator_complex.h"

double modulus_complex(Complex c)
{
    return sqrt(c.real * c.real + c.imag * c.imag);
}