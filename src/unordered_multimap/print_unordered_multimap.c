#include "unordered_multimap/print_unordered_multimap.h"

void unordered_multimap_print(UnorderedMultimap *map)
{
    printf("{");
    int first = 1;
    for (int i = 0; i < map->capacity; i++)
    {
        UnorderedMultimapNode *cur = map->buckets[i];
        while (cur)
        {
            if (!first)
            {
                printf(", ");
            }
            printf("%d: %d", cur->key, cur->value);
            first = 0;
            cur = cur->next;
        }
    }
    printf("}\n");
}
