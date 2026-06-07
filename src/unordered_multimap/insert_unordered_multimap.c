#include "unordered_multimap/insert_unordered_multimap.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_multimap_put(UnorderedMultimap *map, int key, int value)
{
    int idx = hash_key(key, map->capacity);

    UnorderedMultimapNode *node = (UnorderedMultimapNode *)malloc(sizeof(UnorderedMultimapNode));
    if (!node) return;
    node->key = key;
    node->value = value;
    node->next = map->buckets[idx];
    map->buckets[idx] = node;
    map->size++;
}
