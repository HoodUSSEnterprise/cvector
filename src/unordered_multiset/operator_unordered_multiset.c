#include "unordered_multiset/operator_unordered_multiset.h"

int unordered_multiset_size(UnorderedMultiset *set)
{
    return set->size;
}

int unordered_multiset_unique(UnorderedMultiset *set)
{
    return set->unique;
}

int unordered_multiset_is_empty(UnorderedMultiset *set)
{
    return set->size == 0;
}
