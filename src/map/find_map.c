#include "map/find_map.h"

int *map_get(Map *map, int key)
{
    MapNode *x = map->root;
    while (x != map->nil)
    {
        if (key == x->key)
            return &x->value;
        else if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return NULL;
}

bool map_contains(Map *map, int key)
{
    return map_get(map, key) != NULL;
}
