#ifndef FIND_MAP_H
#define FIND_MAP_H

#include "map/base_map.h"
#include <stdbool.h>

int *map_get(Map *map, int key);
bool map_contains(Map *map, int key);

#endif
