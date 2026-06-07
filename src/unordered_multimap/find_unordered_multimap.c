#include "unordered_multimap/find_unordered_multimap.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

int *unordered_multimap_get(UnorderedMultimap *map, int key)
{
    int idx = hash_key(key, map->capacity);

    UnorderedMultimapNode *cur = map->buckets[idx];
    while (cur)
    {
        if (cur->key == key)
        {
            return &cur->value;
        }
        cur = cur->next;
    }
    return NULL;
}

int unordered_multimap_contains(UnorderedMultimap *map, int key)
{
    return unordered_multimap_get(map, key) != NULL;
}
