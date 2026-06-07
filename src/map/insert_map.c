#include "map/insert_map.h"

static void left_rotate(Map *map, MapNode *x)
{
    MapNode *y = x->right;
    x->right = y->left;
    if (y->left != map->nil)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == map->nil)
    {
        map->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

static void right_rotate(Map *map, MapNode *x)
{
    MapNode *y = x->left;
    x->left = y->right;
    if (y->right != map->nil)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == map->nil)
    {
        map->root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

static void insert_fixup(Map *map, MapNode *z)
{
    while (z->parent->color == MAP_RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            MapNode *y = z->parent->parent->right;
            if (y->color == MAP_RED)
            {
                z->parent->color = MAP_BLACK;
                y->color = MAP_BLACK;
                z->parent->parent->color = MAP_RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotate(map, z);
                }
                z->parent->color = MAP_BLACK;
                z->parent->parent->color = MAP_RED;
                right_rotate(map, z->parent->parent);
            }
        }
        else
        {
            MapNode *y = z->parent->parent->left;
            if (y->color == MAP_RED)
            {
                z->parent->color = MAP_BLACK;
                y->color = MAP_BLACK;
                z->parent->parent->color = MAP_RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(map, z);
                }
                z->parent->color = MAP_BLACK;
                z->parent->parent->color = MAP_RED;
                left_rotate(map, z->parent->parent);
            }
        }
    }
    map->root->color = MAP_BLACK;
}

void map_put(Map *map, int key, int value)
{
    MapNode *x = map->root;
    MapNode *y = map->nil;

    while (x != map->nil)
    {
        y = x;
        if (key == x->key)
        {
            x->value = value;
            return;
        }
        else if (key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    MapNode *z = (MapNode *)malloc(sizeof(MapNode));
    if (z == NULL)
    {
        return;
    }
    z->key = key;
    z->value = value;
    z->color = MAP_RED;
    z->left = map->nil;
    z->right = map->nil;

    z->parent = y;
    if (y == map->nil)
    {
        map->root = z;
    }
    else if (key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }

    map->size++;
    insert_fixup(map, z);
}
