#include "hashtable/hash_table.h"
#include <stdio.h>

int main()
{
    HashTable *ht = create_hash_table();

    hash_table_insert(ht, "apple", 10);
    hash_table_insert(ht, "banana", 20);
    hash_table_insert(ht, "orange", 20);
    hash_table_insert(ht, "fruit", 40);

    int *val = hash_table_get(ht, "apple");
    if (val)
    {
        printf("apple = %d\n", *val);
    }
    int *val_orange = hash_table_get(ht, "orange");
    int *val_banana = hash_table_get(ht, "banana");
    if (val_orange && val_banana)
    {
        printf("orange = %d\n", *val_orange);
        printf("banana = %d\n", *val_banana);
    }

    hash_table_delete(ht, "banana");
    free_hash_table(ht);

    return 0;
}