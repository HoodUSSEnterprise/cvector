#ifndef BASE_STACK_H
#define BASE_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
    int size;
} Stack;

#endif // BASE_STACK_H