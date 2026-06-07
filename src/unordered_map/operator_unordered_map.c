#include "unordered_map/operator_unordered_map.h"

int unordered_map_size(UnorderedMap *map)
{
    return map->size;
}

int unordered_map_is_empty(UnorderedMap *map)
{
    return map->size == 0;
}
