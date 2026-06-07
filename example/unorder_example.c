#include "unordered_map/unordered_map.h"
#include "unordered_set/unordered_set.h"

int main(void)
{
    printf("=== Unordered Map ===\n");
    UnorderedMap *map = create_unordered_map();

    unordered_map_put(map, 3, 30);
    unordered_map_put(map, 1, 10);
    unordered_map_put(map, 4, 40);
    unordered_map_put(map, 2, 20);
    unordered_map_put(map, 5, 50);

    printf("After inserts:\n");
    unordered_map_print(map);
    printf("Size: %d\n\n", unordered_map_size(map));

    /* Update */
    unordered_map_put(map, 3, 99);
    printf("After updating key 3 to 99:\n");
    unordered_map_print(map);
    printf("Size: %d\n\n", unordered_map_size(map));

    /* Get */
    int *v = unordered_map_get(map, 2);
    if (v)
    {
        printf("get(2) = %d\n", *v);
    }
    printf("get(9) = %s\n\n", unordered_map_contains(map, 9) ? "found" : "NULL");

    /* Delete */
    unordered_map_delete(map, 1);
    unordered_map_delete(map, 4);
    printf("After deleting 1, 4:\n");
    unordered_map_print(map);
    printf("Size: %d\n\n", unordered_map_size(map));

    printf("Is empty? %s\n\n", unordered_map_is_empty(map) ? "yes" : "no");

    free_unordered_map(map);

    printf("=== Unordered Set ===\n");
    UnorderedSet *set = create_unordered_set();

    int vals[] = {5, 3, 8, 1, 4, 7, 9, 2, 6, 5, 3};
    int n = sizeof(vals) / sizeof(vals[0]);
    printf("Inserting:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vals[i]);
        unordered_set_insert(set, vals[i]);
    }
    printf("\n");

    printf("Set contents: ");
    unordered_set_print(set);
    printf("Size: %d\n\n", unordered_set_size(set));

    printf("Contains 4? %s\n", unordered_set_contains(set, 4) ? "yes" : "no");
    printf("Contains 0? %s\n\n", unordered_set_contains(set, 0) ? "yes" : "no");

    unordered_set_delete(set, 3);
    unordered_set_delete(set, 8);
    printf("After deleting 3, 8:\n");
    unordered_set_print(set);
    printf("Size: %d\n\n", unordered_set_size(set));

    printf("Is empty? %s\n", unordered_set_is_empty(set) ? "yes" : "no");

    free_unordered_set(set);
    return 0;
}
