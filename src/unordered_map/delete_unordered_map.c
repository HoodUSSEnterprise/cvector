#include "unordered_map/delete_unordered_map.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_map_delete(UnorderedMap *map, int key)
{
    int idx = hash_key(key, map->capacity);

    UnorderedMapNode *cur = map->buckets[idx];
    UnorderedMapNode *prev = NULL;

    while (cur)
    {
        if (cur->key == key)
        {
            if (prev)
                prev->next = cur->next;
            else
                map->buckets[idx] = cur->next;
            free(cur);
            map->size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
