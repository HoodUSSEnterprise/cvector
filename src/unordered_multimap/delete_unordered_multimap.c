#include "unordered_multimap/delete_unordered_multimap.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_multimap_delete(UnorderedMultimap *map, int key)
{
    int idx = hash_key(key, map->capacity);

    UnorderedMultimapNode *cur = map->buckets[idx];
    UnorderedMultimapNode *prev = NULL;

    while (cur)
    {
        if (cur->key == key)
        {
            if (prev)
            {
                prev->next = cur->next;
            }
            else
            {
                map->buckets[idx] = cur->next;
            }
            free(cur);
            map->size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
