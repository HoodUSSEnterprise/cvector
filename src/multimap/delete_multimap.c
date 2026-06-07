#include "multimap/delete_multimap.h"

static void left_rotate(MultiMap *map, MultiMapNode *x)
{
    MultiMapNode *y = x->right;
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

static void right_rotate(MultiMap *map, MultiMapNode *y)
{
    MultiMapNode *x = y->left;
    y->left = x->right;
    if (x->right != map->nil)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == map->nil)
    {
        map->root = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

static void transplant(MultiMap *map, MultiMapNode *u, MultiMapNode *v)
{
    if (u->parent == map->nil)
    {
        map->root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

static MultiMapNode *minimum(MultiMapNode *node, MultiMapNode *nil)
{
    while (node->left != nil)
    {
        node = node->left;
    }
    return node;
}

static void delete_fixup(MultiMap *map, MultiMapNode *x)
{
    while (x != map->root && x->color == MM_BLACK)
    {
        if (x == x->parent->left)
        {
            MultiMapNode *w = x->parent->right;
            if (w->color == MM_RED)
            {
                w->color = MM_BLACK;
                x->parent->color = MM_RED;
                left_rotate(map, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == MM_BLACK && w->right->color == MM_BLACK)
            {
                w->color = MM_RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == MM_BLACK)
                {
                    w->left->color = MM_BLACK;
                    w->color = MM_RED;
                    right_rotate(map, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = MM_BLACK;
                w->right->color = MM_BLACK;
                left_rotate(map, x->parent);
                x = map->root;
            }
        }
        else
        {
            MultiMapNode *w = x->parent->left;
            if (w->color == MM_RED)
            {
                w->color = MM_BLACK;
                x->parent->color = MM_RED;
                right_rotate(map, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == MM_BLACK && w->left->color == MM_BLACK)
            {
                w->color = MM_RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == MM_BLACK)
                {
                    w->right->color = MM_BLACK;
                    w->color = MM_RED;
                    left_rotate(map, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = MM_BLACK;
                w->left->color = MM_BLACK;
                right_rotate(map, x->parent);
                x = map->root;
            }
        }
    }
    x->color = MM_BLACK;
}

static MultiMapNode *find_node(MultiMap *map, int key)
{
    MultiMapNode *cur = map->root;
    while (cur != map->nil)
    {
        if (key < cur->key)
        {
            cur = cur->left;
        }
        else if (key > cur->key)
        {
            cur = cur->right;
        }
        else
        {
            return cur;
        }
    }
    return NULL;
}

void multimap_delete(MultiMap *map, int key)
{
    MultiMapNode *z = find_node(map, key);
    if (!z)
    {
        return;
    }

    MultiMapNode *y = z;
    MultiMapNode *x;
    MultiMapColor y_orig = y->color;

    if (z->left == map->nil)
    {
        x = z->right;
        transplant(map, z, z->right);
    }
    else if (z->right == map->nil)
    {
        x = z->left;
        transplant(map, z, z->left);
    }
    else
    {
        y = minimum(z->right, map->nil);
        y_orig = y->color;
        x = y->right;
        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(map, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(map, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    free(z);
    map->size--;

    if (y_orig == MM_BLACK)
    {
        delete_fixup(map, x);
    }
}
