#ifndef OPERATION_COMPLEX_H
#define OPERATION_COMPLEX_H

#include "complex/base_complex.h"
#include <stdbool.h>
#include <math.h>

Complex create_complex(double real, double imag);

Complex add_complex(Complex c1, Complex c2);

Complex sub_complex(Complex c1, Complex c2);

Complex mul_complex(Complex c1, Complex c2);

Complex div_complex(Complex c1, Complex c2);

Complex power_complex(Complex c1, int k);

double modulus_complex(Complex c);

bool is_equal_complex(Complex c1, Complex c2);

#endif