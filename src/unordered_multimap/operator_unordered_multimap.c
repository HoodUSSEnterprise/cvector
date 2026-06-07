#include "unordered_multimap/operator_unordered_multimap.h"

int unordered_multimap_size(UnorderedMultimap *map)
{
    return map->size;
}

int unordered_multimap_is_empty(UnorderedMultimap *map)
{
    return map->size == 0;
}
