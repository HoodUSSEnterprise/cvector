#include "set/operator_set.h"

int set_size(Set *set)
{
    return rbtree_size(set->tree);
}

bool set_is_empty(Set *set)
{
    return rbtree_is_empty(set->tree);
}

int set_min(Set *set)
{
    return rbtree_min(set->tree);
}

int set_max(Set *set)
{
    return rbtree_max(set->tree);
}

void set_print(Set *set)
{
    rbtree_print_inorder(set->tree);
}
