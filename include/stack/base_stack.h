#ifndef BASE_STACK_H
#define BASE_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StackIntNode
{
    int data;
    struct StackIntNode *next;
} StackIntNode;

typedef struct
{
    StackIntNode *top;
    int size;
} StackInt;

typedef struct StackFloatNode
{
    float data;
    struct StackFloatNode *next;
} StackFloatNode;

typedef struct
{
    StackFloatNode *top;
    int size;
} StackFloat;

typedef struct StackDoubleNode
{
    double data;
    struct StackDoubleNode *next;
} StackDoubleNode;

typedef struct
{
    StackDoubleNode *top;
    int size;
} StackDouble;

#endif // BASE_STACK_H