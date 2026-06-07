#ifndef INSERT_HASH_TABLE_H
#define INSERT_HASH_TABLE_H

#include "hashtable/base_hash_table.h"
#include <stdlib.h>
#include <string.h>

int hash_table_insert(HashTable *ht, const char *key, int value);

#endif // INSERT_HASH_TABLE_H