#include "map/free_map.h"

static void free_nodes(Map *map, MapNode *x)
{
    if (x == map->nil) return;
    free_nodes(map, x->left);
    free_nodes(map, x->right);
    free(x);
}

void free_map(Map *map)
{
    if (map == NULL) return;
    free_nodes(map, map->root);
    free(map->nil);
    free(map);
}
