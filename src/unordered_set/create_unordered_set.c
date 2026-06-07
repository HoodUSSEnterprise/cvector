#include "unordered_set/create_unordered_set.h"

UnorderedSet *create_unordered_set(void)
{
    UnorderedSet *set = (UnorderedSet *)malloc(sizeof(UnorderedSet));
    if (!set) return NULL;
    set->capacity = UNORDERED_SET_INITIAL_CAPACITY;
    set->size = 0;
    set->buckets = (UnorderedSetNode **)calloc(set->capacity, sizeof(UnorderedSetNode *));
    if (!set->buckets)
    {
        free(set);
        return NULL;
    }
    return set;
}
