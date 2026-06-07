#include "multiset/find_multiset.h"

int multiset_contains(MultiSet *set, int key)
{
    return rbtree_contains(set->tree, key);
}

int multiset_count(MultiSet *set, int key)
{
    return rbtree_count(set->tree, key);
}
