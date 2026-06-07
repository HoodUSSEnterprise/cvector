#include "unordered_map/insert_unordered_map.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_map_put(UnorderedMap *map, int key, int value)
{
    int idx = hash_key(key, map->capacity);

    UnorderedMapNode *cur = map->buckets[idx];
    while (cur)
    {
        if (cur->key == key)
        {
            cur->value = value;
            return;
        }
        cur = cur->next;
    }

    UnorderedMapNode *node = (UnorderedMapNode *)malloc(sizeof(UnorderedMapNode));
    if (!node)
    {
        return;
    }
    node->key = key;
    node->value = value;
    node->next = map->buckets[idx];
    map->buckets[idx] = node;
    map->size++;
}
