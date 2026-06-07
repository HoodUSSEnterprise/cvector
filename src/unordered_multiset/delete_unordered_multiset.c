#include "unordered_multiset/delete_unordered_multiset.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_multiset_delete(UnorderedMultiset *set, int key)
{
    int idx = hash_key(key, set->capacity);

    UnorderedMultisetNode *cur = set->buckets[idx];
    UnorderedMultisetNode *prev = NULL;

    while (cur)
    {
        if (cur->key == key)
        {
            if (cur->count > 1)
            {
                cur->count--;
                set->size--;
                return;
            }

            if (prev)
            {
                prev->next = cur->next;
            }
            else
            {
                set->buckets[idx] = cur->next;
            }
            free(cur);
            set->size--;
            set->unique--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
