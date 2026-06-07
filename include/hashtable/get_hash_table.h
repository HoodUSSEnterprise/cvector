#ifndef GET_HASH_TABLE_H
#define GET_HASH_TABLE_H

#include "hashtable/base_hash_table.h"
#include <string.h>

int *hash_table_get(HashTable *ht, const char *key);

#endif // GET_HASH_TABLE_H