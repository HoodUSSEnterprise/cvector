#include "complex/free_complex.h"

void free_complex(Complex **c)
{
    if (c == NULL || *c == NULL)
    {
        return;
    }
    else
    {
        free(*c);
        *c = NULL;
    }
}