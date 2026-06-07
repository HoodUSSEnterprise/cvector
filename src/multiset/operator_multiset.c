#include "multiset/operator_multiset.h"

int multiset_size(MultiSet *set)
{
    return rbtree_size(set->tree);
}

int multiset_is_empty(MultiSet *set)
{
    return rbtree_is_empty(set->tree);
}

int multiset_min(MultiSet *set)
{
    return rbtree_min(set->tree);
}

int multiset_max(MultiSet *set)
{
    return rbtree_max(set->tree);
}
