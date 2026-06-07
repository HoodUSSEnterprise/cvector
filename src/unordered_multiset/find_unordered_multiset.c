#include "unordered_multiset/find_unordered_multiset.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

int unordered_multiset_contains(UnorderedMultiset *set, int key)
{
    int idx = hash_key(key, set->capacity);

    UnorderedMultisetNode *cur = set->buckets[idx];
    while (cur)
    {
        if (cur->key == key)
        {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

int unordered_multiset_count(UnorderedMultiset *set, int key)
{
    int idx = hash_key(key, set->capacity);

    UnorderedMultisetNode *cur = set->buckets[idx];
    while (cur)
    {
        if (cur->key == key)
        {
            return cur->count;
        }
        cur = cur->next;
    }
    return 0;
}
