#ifndef OPERATOR_STACK_H
#define OPERATOR_STACK_H

#include "stack/base_stack.h"
#include <stdbool.h>

int top_int(StackInt *stack, int *data);

float top_float(StackFloat *stack, float *data);

double top_double(StackDouble *stack, double *data);

bool is_empty_stack_int(StackInt *stack);

bool is_empty_stack_float(StackFloat *stack);

bool is_empty_stack_double(StackDouble *stack);

int get_stack_size_int(StackInt *stack);

float get_stack_size_float(StackFloat *stack);

double get_stack_size_double(StackDouble *stack);

#define top(stack, data) _Generic((stack), \
    StackInt *: top_int,                   \
    StackFloat *: top_float,               \
    StackDouble *: top_double)(stack, data)

#define is_empty_stack(stack) _Generic((stack), \
    StackInt *: is_empty_stack_int,             \
    StackFloat *: is_empty_stack_float,         \
    StackDouble *: is_empty_stack_double)(stack)

#define get_stack_size(stack) _Generic((stack), \
    StackInt *: get_stack_size_int,             \
    StackFloat *: get_stack_size_float,         \
    StackDouble *: get_stack_size_double)(stack)
#endif // OPERATOR_STACK_H
