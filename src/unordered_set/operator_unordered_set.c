#include "unordered_set/operator_unordered_set.h"

int unordered_set_size(UnorderedSet *set)
{
    return set->size;
}

int unordered_set_is_empty(UnorderedSet *set)
{
    return set->size == 0;
}
