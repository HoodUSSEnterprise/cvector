#include "hashtable/free_hash_table.h"

void free_hash_table(HashTable *ht)
{
    if (ht == NULL || ht->buckets == NULL)
    {
        printf("Invalid param\n");
        return;
    }

    for (int i = 0; i < ht->table_size; i++)
    {
        HashNode *curr = ht->buckets[i];
        while (curr)
        {
            HashNode *temp = curr;
            curr = curr->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}