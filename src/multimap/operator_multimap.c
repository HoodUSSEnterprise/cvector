#include "multimap/operator_multimap.h"

int multimap_size(MultiMap *map)
{
    return map->size;
}

int multimap_is_empty(MultiMap *map)
{
    return map->size == 0;
}
