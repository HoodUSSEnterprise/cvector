#include "unordered_multiset/print_unordered_multiset.h"

void unordered_multiset_print(UnorderedMultiset *set)
{
    printf("{");
    int first = 1;
    for (int i = 0; i < set->capacity; i++)
    {
        UnorderedMultisetNode *cur = set->buckets[i];
        while (cur)
        {
            for (int j = 0; j < cur->count; j++)
            {
                if (!first) printf(", ");
                printf("%d", cur->key);
                first = 0;
            }
            cur = cur->next;
        }
    }
    printf("}\n");
}
