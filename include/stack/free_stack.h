#ifndef FREE_STACK_H
#define FREE_STACK_H

#include "stack/base_stack.h"

void free_stack_int(StackInt *stack);

void free_stack_float(StackFloat *stack);

void free_stack_double(StackDouble *stack);

#define free_stack(stack) _Generic((stack), \
    StackInt *: free_stack_int,             \
    StackFloat *: free_stack_float,         \
    StackDouble *: free_stack_double)(stack)

#endif // FREE_STACK_H