#include "complex/operator_complex.h"

Complex add_complex(Complex c1, Complex c2)
{
    Complex res = {0, 0};
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

Complex sub_complex(Complex c1, Complex c2)
{
    Complex res = {0, 0};
    res.real = c1.real - c2.real;
    res.imag = c1.imag - c2.imag;
    return res;
}

Complex mul_complex(Complex c1, Complex c2)
{
    Complex res = {0, 0};
    res.real = c1.real * c2.real - c1.imag * c2.imag;
    res.imag = c1.real * c2.imag + c1.imag * c2.real;
    return res;
}

Complex div_complex(Complex c1, Complex c2)
{
    Complex res = {0, 0};
    double k = c2.real * c2.real + c2.imag * c2.imag;
    res.real = (c1.real * c2.real + c1.imag * c2.imag) / k;
    res.imag = (c1.imag * c2.real - c1.real * c2.imag) / k;
    return res;
}

Complex power_complex(Complex c1, int k)
{
    Complex res = {1, 0};
    for (int i = 0; i < k; i++)
    {
        res = mul_complex(res, c1); 
    }
    return res;
}

double modulus_complex(Complex c)
{
    return sqrt(c.real * c.real + c.imag * c.imag);
}

bool is_equal_complex(Complex c1, Complex c2)
{
    return (fabs(c1.real - c2.real) < 1e-6) && (fabs(c1.imag - c2.imag) < 1e-6);
    // return (c1.real == c2.real) && (c1.imag == c2.imag);
}