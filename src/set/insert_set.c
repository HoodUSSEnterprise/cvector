#include "set/insert_set.h"

void set_insert(Set *set, int key)
{
    rbtree_insert(set->tree, key);
}
