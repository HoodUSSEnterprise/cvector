#include "unordered_set/print_unordered_set.h"

void unordered_set_print(UnorderedSet *set)
{
    printf("{");
    int first = 1;
    for (int i = 0; i < set->capacity; i++)
    {
        UnorderedSetNode *cur = set->buckets[i];
        while (cur)
        {
            if (!first)
            {
                printf(", ");
            }
            printf("%d", cur->key);
            first = 0;
            cur = cur->next;
        }
    }
    printf("}\n");
}
