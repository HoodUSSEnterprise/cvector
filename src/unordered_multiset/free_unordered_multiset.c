#include "unordered_multiset/free_unordered_multiset.h"

void clear_unordered_multiset(UnorderedMultiset *set)
{
    for (int i = 0; i < set->capacity; i++)
    {
        UnorderedMultisetNode *cur = set->buckets[i];
        while (cur)
        {
            UnorderedMultisetNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        set->buckets[i] = NULL;
    }
    set->size = 0;
    set->unique = 0;
}

void free_unordered_multiset(UnorderedMultiset *set)
{
    if (!set) return;
    clear_unordered_multiset(set);
    free(set->buckets);
    free(set);
}
