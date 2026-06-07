#include "map/delete_map.h"

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

static MapNode *min_node(Map *map, MapNode *x)
{
    while (x->left != map->nil)
    {
        x = x->left;
    }
    return x;
}

static void transplant(Map *map, MapNode *u, MapNode *v)
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

static void delete_fixup(Map *map, MapNode *x)
{
    while (x != map->root && x->color == MAP_BLACK)
    {
        if (x == x->parent->left)
        {
            MapNode *w = x->parent->right;
            if (w->color == MAP_RED)
            {
                w->color = MAP_BLACK;
                x->parent->color = MAP_RED;
                left_rotate(map, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == MAP_BLACK && w->right->color == MAP_BLACK)
            {
                w->color = MAP_RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == MAP_BLACK)
                {
                    w->left->color = MAP_BLACK;
                    w->color = MAP_RED;
                    right_rotate(map, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = MAP_BLACK;
                w->right->color = MAP_BLACK;
                left_rotate(map, x->parent);
                x = map->root;
            }
        }
        else
        {
            MapNode *w = x->parent->left;
            if (w->color == MAP_RED)
            {
                w->color = MAP_BLACK;
                x->parent->color = MAP_RED;
                right_rotate(map, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == MAP_BLACK && w->left->color == MAP_BLACK)
            {
                w->color = MAP_RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == MAP_BLACK)
                {
                    w->right->color = MAP_BLACK;
                    w->color = MAP_RED;
                    left_rotate(map, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = MAP_BLACK;
                w->left->color = MAP_BLACK;
                right_rotate(map, x->parent);
                x = map->root;
            }
        }
    }
    x->color = MAP_BLACK;
}

void map_delete(Map *map, int key)
{
    MapNode *z = map->root;
    while (z != map->nil)
    {
        if (key == z->key)
        {
            break;
        }
        else if (key < z->key)
        {
            z = z->left;
        }
        else
        {
            z = z->right;
        }
    }
    if (z == map->nil)
    {
        return;
    }

    MapNode *y = z;
    MapNode *x;
    MapColor y_original_color = y->color;

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
        y = min_node(map, z->right);
        y_original_color = y->color;
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

    if (y_original_color == MAP_BLACK)
    {
        delete_fixup(map, x);
    }
}
