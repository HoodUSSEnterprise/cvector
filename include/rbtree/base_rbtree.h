#ifndef BASE_RBTREE_H
#define BASE_RBTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct RBNode
{
    int key;
    Color color;
    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;
} RBNode;

typedef struct
{
    RBNode *root;
    RBNode *nil;
    int size;
} RBTree;

#endif
