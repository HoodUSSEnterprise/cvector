#ifndef BASE_UNORDERED_SET_H
#define BASE_UNORDERED_SET_H

#include <stdio.h>
#include <stdlib.h>

#define UNORDERED_SET_INITIAL_CAPACITY 16

typedef struct UnorderedSetNode
{
    int key;
    struct UnorderedSetNode *next;
} UnorderedSetNode;

typedef struct
{
    UnorderedSetNode **buckets;
    int size;
    int capacity;
} UnorderedSet;

#endif
