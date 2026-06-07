#include "unordered_map/print_unordered_map.h"

void unordered_map_print(UnorderedMap *map)
{
    printf("{");
    int first = 1;
    for (int i = 0; i < map->capacity; i++)
    {
        UnorderedMapNode *cur = map->buckets[i];
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
