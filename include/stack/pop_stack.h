#ifndef POP_STACK_H
#define POP_STACK_H

#include "stack/base_stack.h"

int pop_int(StackInt *stack, int *data);

float pop_float(StackFloat *stack, float *data);

double pop_double(StackDouble *stack, double *data);

#endif // POP_STACK_H