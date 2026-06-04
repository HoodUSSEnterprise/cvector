#include "complex/free_complex.h"

void free_complex(Complex **c)
{
    free(&c);
}