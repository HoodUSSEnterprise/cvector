#include "hashtable/create_hash_table.h"

#define TABLE_SIZE 100

HashTable *create_hash_table(void)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    ht->buckets = calloc(TABLE_SIZE, sizeof(HashNode *));
    if (ht->buckets == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(ht);
        return NULL;
    }

    ht->size = 0;
    ht->table_size = TABLE_SIZE;
    return ht;
}