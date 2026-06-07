#ifndef BASE_MULTIMAP_H
#define BASE_MULTIMAP_H

#include <stdio.h>
#include <stdlib.h>

typedef enum { MM_RED, MM_BLACK } MultiMapColor;

typedef struct MultiMapNode
{
    int key;
    int value;
    MultiMapColor color;
    struct MultiMapNode *left;
    struct MultiMapNode *right;
    struct MultiMapNode *parent;
} MultiMapNode;

typedef struct
{
    MultiMapNode *root;
    MultiMapNode *nil;
    int size;
} MultiMap;

#endif
