#include "unordered_multiset/create_unordered_multiset.h"

UnorderedMultiset *create_unordered_multiset(void)
{
    UnorderedMultiset *set = (UnorderedMultiset *)malloc(sizeof(UnorderedMultiset));
    if (!set)
    {
        return NULL;
    }
    set->capacity = UNORDERED_MULTISET_INITIAL_CAPACITY;
    set->size = 0;
    set->unique = 0;
    set->buckets = (UnorderedMultisetNode **)calloc(set->capacity, sizeof(UnorderedMultisetNode *));
    if (!set->buckets)
    {
        free(set);
        return NULL;
    }
    return set;
}
