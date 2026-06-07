#include "multimap/create_multimap.h"

MultiMap *create_multimap(void)
{
    MultiMap *map = (MultiMap *)malloc(sizeof(MultiMap));
    if (!map) return NULL;

    map->nil = (MultiMapNode *)malloc(sizeof(MultiMapNode));
    if (!map->nil)
    {
        free(map);
        return NULL;
    }
    map->nil->color = MM_BLACK;
    map->nil->left = map->nil->right = map->nil->parent = map->nil;

    map->root = map->nil;
    map->size = 0;
    return map;
}
