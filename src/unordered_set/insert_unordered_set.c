#include "unordered_set/insert_unordered_set.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_set_insert(UnorderedSet *set, int key)
{
    int idx = hash_key(key, set->capacity);

    UnorderedSetNode *cur = set->buckets[idx];
    while (cur)
    {
        if (cur->key == key)
        {
            return;
        }
        cur = cur->next;
    }

    UnorderedSetNode *node = (UnorderedSetNode *)malloc(sizeof(UnorderedSetNode));
    if (!node)
    {
        return;
    }
    node->key = key;
    node->next = set->buckets[idx];
    set->buckets[idx] = node;
    set->size++;
}
