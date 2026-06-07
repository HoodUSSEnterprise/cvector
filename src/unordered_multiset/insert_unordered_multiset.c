#include "unordered_multiset/insert_unordered_multiset.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_multiset_insert(UnorderedMultiset *set, int key)
{
    int idx = hash_key(key, set->capacity);

    UnorderedMultisetNode *cur = set->buckets[idx];
    while (cur)
    {
        if (cur->key == key)
        {
            cur->count++;
            set->size++;
            return;
        }
        cur = cur->next;
    }

    UnorderedMultisetNode *node = (UnorderedMultisetNode *)malloc(sizeof(UnorderedMultisetNode));
    if (!node)
    {
        return;
    }
    node->key = key;
    node->count = 1;
    node->next = set->buckets[idx];
    set->buckets[idx] = node;
    set->size++;
    set->unique++;
}
