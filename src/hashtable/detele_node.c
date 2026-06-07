#include "hashtable/delete_node.h"

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

int hash_table_delete(HashTable *ht, const char *key)
{
    if (!ht || !key)
    {
        return -1;
    }

    unsigned int index = hash(key, ht->table_size);
    HashNode *curr = ht->buckets[index];
    HashNode *prev = NULL;

    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            else
            {
                ht->buckets[index] = curr->next;
            }
            free(curr->key);
            free(curr);
            ht->size--;
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return -1;
}