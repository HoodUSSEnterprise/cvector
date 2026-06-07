#include "unordered_multimap/create_unordered_multimap.h"

UnorderedMultimap *create_unordered_multimap(void)
{
    UnorderedMultimap *map = (UnorderedMultimap *)malloc(sizeof(UnorderedMultimap));
    if (!map) return NULL;
    map->capacity = UNORDERED_MULTIMAP_INITIAL_CAPACITY;
    map->size = 0;
    map->buckets = (UnorderedMultimapNode **)calloc(map->capacity, sizeof(UnorderedMultimapNode *));
    if (!map->buckets)
    {
        free(map);
        return NULL;
    }
    return map;
}
