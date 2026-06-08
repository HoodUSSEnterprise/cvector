#ifndef PUSH_STACK_H
#define PUSH_STACK_H

#include "stack/base_stack.h"

int push_int(StackInt *stack, int data);

float push_float(StackFloat *stack, float data);

double push_double(StackDouble *stack, double data);

#define push(stack, data) _Generic((stack), \
    StackInt *: push_int,                   \
    StackFloat *: push_float,               \
    StackDouble *: push_double)(stack, data)

#endif // PUSH_STACK_H