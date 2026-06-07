#include "unordered_set/free_unordered_set.h"

void clear_unordered_set(UnorderedSet *set)
{
    for (int i = 0; i < set->capacity; i++)
    {
        UnorderedSetNode *cur = set->buckets[i];
        while (cur)
        {
            UnorderedSetNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        set->buckets[i] = NULL;
    }
    set->size = 0;
}

void free_unordered_set(UnorderedSet *set)
{
    if (!set)
    {
        return;
    }
    clear_unordered_set(set);
    free(set->buckets);
    free(set);
}
