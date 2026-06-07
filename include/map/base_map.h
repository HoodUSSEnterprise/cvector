#ifndef BASE_MAP_H
#define BASE_MAP_H

#include <stdio.h>
#include <stdlib.h>

typedef enum { MAP_RED, MAP_BLACK } MapColor;

typedef struct MapNode
{
    int key;
    int value;
    MapColor color;
    struct MapNode *left;
    struct MapNode *right;
    struct MapNode *parent;
} MapNode;

typedef struct
{
    MapNode *root;
    MapNode *nil;
    int size;
} Map;

#endif
