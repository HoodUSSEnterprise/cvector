#include "unordered_multimap/unordered_multimap.h"

int main(void)
{
    UnorderedMultimap *map = create_unordered_multimap();

    printf("Put (1,10), (2,20), (1,100), (3,30), (1,1000):\n");
    unordered_multimap_put(map, 1, 10);
    unordered_multimap_put(map, 2, 20);
    unordered_multimap_put(map, 1, 100);
    unordered_multimap_put(map, 3, 30);
    unordered_multimap_put(map, 1, 1000);

    printf("Contents: ");
    unordered_multimap_print(map);
    printf("Size: %d\n\n", unordered_multimap_size(map));

    printf("Contains 2? %s\n", unordered_multimap_contains(map, 2) ? "yes" : "no");
    printf("Contains 5? %s\n\n", unordered_multimap_contains(map, 5) ? "yes" : "no");

    int *v = unordered_multimap_get(map, 1);
    if (v)
    {
        printf("get(1) = %d (first occurrence)\n", *v);
    }

    printf("\nDelete key 1 (once):\n");
    unordered_multimap_delete(map, 1);
    unordered_multimap_print(map);
    printf("Size: %d\n", unordered_multimap_size(map));

    printf("Is empty? %s\n", unordered_multimap_is_empty(map) ? "yes" : "no");

    free_unordered_multimap(map);
    return 0;
}
