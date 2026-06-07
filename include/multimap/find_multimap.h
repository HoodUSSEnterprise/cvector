#ifndef FIND_MULTIMAP_H
#define FIND_MULTIMAP_H

#include "multimap/base_multimap.h"

int *multimap_get(MultiMap *map, int key);
int multimap_contains(MultiMap *map, int key);

#endif
