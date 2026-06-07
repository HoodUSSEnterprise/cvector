#include "hashtable/insert_hash_table.h"

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

static HashNode *create_node(const char *key, int value)
{
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    if (!node)
    {
        return NULL;
    }

    node->key = (char *)malloc(strlen(key) + 1);
    if (!node->key)
    {
        free(node);
        return NULL;
    }

    strcpy(node->key, key);
    node->value = value;
    node->next = NULL;
    return node;
}

int hash_table_insert(HashTable *ht, const char *key, int value)
{
    if (!ht || !key)
    {
        return -1;
    }

    unsigned int index = hash(key, ht->table_size);
    HashNode *curr = ht->buckets[index];

    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            curr->value = value;
            return 0;
        }
        curr = curr->next;
    }

    HashNode *new_node = create_node(key, value);
    if (!new_node)
    {
        return -1;
    }

    new_node->next = ht->buckets[index];
    ht->buckets[index] = new_node;
    ht->size++;
    return 0;
}