#include "unordered_multimap/free_unordered_multimap.h"

void clear_unordered_multimap(UnorderedMultimap *map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        UnorderedMultimapNode *cur = map->buckets[i];
        while (cur)
        {
            UnorderedMultimapNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        map->buckets[i] = NULL;
    }
    map->size = 0;
}

void free_unordered_multimap(UnorderedMultimap *map)
{
    if (!map)
    {
        return;
    }
    clear_unordered_multimap(map);
    free(map->buckets);
    free(map);
}
