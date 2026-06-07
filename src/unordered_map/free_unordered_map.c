#include "unordered_map/free_unordered_map.h"

void clear_unordered_map(UnorderedMap *map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        UnorderedMapNode *cur = map->buckets[i];
        while (cur)
        {
            UnorderedMapNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        map->buckets[i] = NULL;
    }
    map->size = 0;
}

void free_unordered_map(UnorderedMap *map)
{
    if (!map)
    {
        return;
    }
    clear_unordered_map(map);
    free(map->buckets);
    free(map);
}
