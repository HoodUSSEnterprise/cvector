#include "set/find_set.h"

bool set_contains(Set *set, int key)
{
    return rbtree_contains(set->tree, key);
}
