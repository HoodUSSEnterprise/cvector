#include "unordered_set/find_unordered_set.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

int unordered_set_contains(UnorderedSet *set, int key)
{
    int idx = hash_key(key, set->capacity);

    UnorderedSetNode *cur = set->buckets[idx];
    while (cur)
    {
        if (cur->key == key) return 1;
        cur = cur->next;
    }
    return 0;
}
