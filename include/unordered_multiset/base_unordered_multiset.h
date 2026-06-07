#ifndef BASE_UNORDERED_MULTISET_H
#define BASE_UNORDERED_MULTISET_H

#include <stdio.h>
#include <stdlib.h>

#define UNORDERED_MULTISET_INITIAL_CAPACITY 16

typedef struct UnorderedMultisetNode
{
    int key;
    int count;
    struct UnorderedMultisetNode *next;
} UnorderedMultisetNode;

typedef struct
{
    UnorderedMultisetNode **buckets;
    int size;
    int capacity;
    int unique;
} UnorderedMultiset;

#endif
