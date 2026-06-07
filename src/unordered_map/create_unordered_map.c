#include "unordered_map/create_unordered_map.h"

UnorderedMap *create_unordered_map(void)
{
    UnorderedMap *map = (UnorderedMap *)malloc(sizeof(UnorderedMap));
    if (!map)
    {
        return NULL;
    }
    map->capacity = UNORDERED_MAP_INITIAL_CAPACITY;
    map->size = 0;
    map->buckets = (UnorderedMapNode **)calloc(map->capacity, sizeof(UnorderedMapNode *));
    if (!map->buckets)
    {
        free(map);
        return NULL;
    }
    return map;
}
