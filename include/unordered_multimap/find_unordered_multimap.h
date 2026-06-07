#ifndef FIND_UNORDERED_MULTIMAP_H
#define FIND_UNORDERED_MULTIMAP_H

#include "unordered_multimap/base_unordered_multimap.h"

int *unordered_multimap_get(UnorderedMultimap *map, int key);
int unordered_multimap_contains(UnorderedMultimap *map, int key);

#endif
