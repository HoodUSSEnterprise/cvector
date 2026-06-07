#ifndef DELETE_NODE_H
#define DELETE_NODE_H

#include "hashtable/base_hash_table.h"
#include <stdlib.h>
#include <string.h>

int hash_table_delete(HashTable *ht, const char *key);

#endif // DELETE_NODE_H