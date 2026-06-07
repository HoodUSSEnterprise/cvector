#ifndef BASE_UNORDERED_MULTIMAP_H
#define BASE_UNORDERED_MULTIMAP_H

#include <stdio.h>
#include <stdlib.h>

#define UNORDERED_MULTIMAP_INITIAL_CAPACITY 16

typedef struct UnorderedMultimapNode
{
    int key;
    int value;
    struct UnorderedMultimapNode *next;
} UnorderedMultimapNode;

typedef struct
{
    UnorderedMultimapNode **buckets;
    int size;
    int capacity;
} UnorderedMultimap;

#endif
