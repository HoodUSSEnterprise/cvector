#include "unordered_set/delete_unordered_set.h"

static int hash_key(int key, int capacity)
{
    return abs(key) % capacity;
}

void unordered_set_delete(UnorderedSet *set, int key)
{
    int idx = hash_key(key, set->capacity);

    UnorderedSetNode *cur = set->buckets[idx];
    UnorderedSetNode *prev = NULL;

    while (cur)
    {
        if (cur->key == key)
        {
            if (prev)
                prev->next = cur->next;
            else
                set->buckets[idx] = cur->next;
            free(cur);
            set->size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
