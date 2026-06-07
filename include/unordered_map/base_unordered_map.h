#ifndef BASE_UNORDERED_MAP_H
#define BASE_UNORDERED_MAP_H

#include <stdio.h>
#include <stdlib.h>

#define UNORDERED_MAP_INITIAL_CAPACITY 16

typedef struct UnorderedMapNode
{
    int key;
    int value;
    struct UnorderedMapNode *next;
} UnorderedMapNode;

typedef struct
{
    UnorderedMapNode **buckets;
    int size;
    int capacity;
} UnorderedMap;

#endif
