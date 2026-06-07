#include "unordered_map/find_unordered_map.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

int *unordered_map_get(UnorderedMap *map, int key)
{
    int idx = hash_key(key, map->capacity);

    UnorderedMapNode *cur = map->buckets[idx];
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

int unordered_map_contains(UnorderedMap *map, int key)
{
    return unordered_map_get(map, key) != NULL;
}
