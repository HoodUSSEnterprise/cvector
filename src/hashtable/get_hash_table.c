#include "hashtable/get_hash_table.h"

static unsigned int hash(const char *key, int table_size)
{
    unsigned int hash = 5381;
    int c;
    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % table_size;
}

int *hash_table_get(HashTable *ht, const char *key)
{
    if (!ht || !key)
    {
        return NULL;
    }

    unsigned int index = hash(key, ht->table_size);
    HashNode *curr = ht->buckets[index];

    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            return &curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}