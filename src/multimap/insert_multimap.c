#include "multimap/insert_multimap.h"

static void left_rotate(MultiMap *map, MultiMapNode *x)
{
    MultiMapNode *y = x->right;
    x->right = y->left;
    if (y->left != map->nil) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == map->nil)
        map->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

static void right_rotate(MultiMap *map, MultiMapNode *y)
{
    MultiMapNode *x = y->left;
    y->left = x->right;
    if (x->right != map->nil) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == map->nil)
        map->root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

static void insert_fixup(MultiMap *map, MultiMapNode *z)
{
    while (z->parent->color == MM_RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            MultiMapNode *y = z->parent->parent->right;
            if (y->color == MM_RED)
            {
                z->parent->color = MM_BLACK;
                y->color = MM_BLACK;
                z->parent->parent->color = MM_RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotate(map, z);
                }
                z->parent->color = MM_BLACK;
                z->parent->parent->color = MM_RED;
                right_rotate(map, z->parent->parent);
            }
        }
        else
        {
            MultiMapNode *y = z->parent->parent->left;
            if (y->color == MM_RED)
            {
                z->parent->color = MM_BLACK;
                y->color = MM_BLACK;
                z->parent->parent->color = MM_RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(map, z);
                }
                z->parent->color = MM_BLACK;
                z->parent->parent->color = MM_RED;
                left_rotate(map, z->parent->parent);
            }
        }
    }
    map->root->color = MM_BLACK;
}

void multimap_put(MultiMap *map, int key, int value)
{
    MultiMapNode *z = (MultiMapNode *)malloc(sizeof(MultiMapNode));
    if (!z) return;
    z->key = key;
    z->value = value;
    z->color = MM_RED;
    z->left = z->right = z->parent = map->nil;

    MultiMapNode *y = map->nil;
    MultiMapNode *x = map->root;
    while (x != map->nil)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == map->nil)
        map->root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    map->size++;
    insert_fixup(map, z);
}
