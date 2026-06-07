#include "set/delete_set.h"

void set_delete(Set *set, int key)
{
    rbtree_delete(set->tree, key);
}
