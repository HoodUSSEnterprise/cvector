#include "map/create_map.h"

Map *create_map(void)
{
    Map *map = (Map *)malloc(sizeof(Map));
    if (map == NULL) return NULL;
    map->nil = (MapNode *)malloc(sizeof(MapNode));
    if (map->nil == NULL)
    {
        free(map);
        return NULL;
    }
    map->nil->color = MAP_BLACK;
    map->nil->left = NULL;
    map->nil->right = NULL;
    map->nil->parent = NULL;
    map->root = map->nil;
    map->size = 0;
    return map;
}
