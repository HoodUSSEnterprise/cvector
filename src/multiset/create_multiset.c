#include "multiset/create_multiset.h"

MultiSet *create_multiset(void)
{
    MultiSet *set = (MultiSet *)malloc(sizeof(MultiSet));
    if (!set) return NULL;
    set->tree = create_rbtree();
    if (!set->tree)
    {
        free(set);
        return NULL;
    }
    return set;
}
