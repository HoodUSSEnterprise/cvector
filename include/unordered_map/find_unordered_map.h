#ifndef FIND_UNORDERED_MAP_H
#define FIND_UNORDERED_MAP_H

#include "unordered_map/base_unordered_map.h"

int *unordered_map_get(UnorderedMap *map, int key);
int unordered_map_contains(UnorderedMap *map, int key);

#endif
