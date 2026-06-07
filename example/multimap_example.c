#include "multimap/multimap.h"

int main(void)
{
    MultiMap *map = create_multimap();

    printf("Put (1,10), (2,20), (1,100), (3,30), (1,1000):\n");
    multimap_put(map, 1, 10);
    multimap_put(map, 2, 20);
    multimap_put(map, 1, 100);
    multimap_put(map, 3, 30);
    multimap_put(map, 1, 1000);

    printf("Inorder: ");
    multimap_print(map);
    printf("Size: %d\n\n", multimap_size(map));

    printf("Contains 2? %s\n", multimap_contains(map, 2) ? "yes" : "no");
    printf("Contains 5? %s\n\n", multimap_contains(map, 5) ? "yes" : "no");

    int *v = multimap_get(map, 1);
    if (v) printf("get(1) = %d\n", *v);

    printf("\nDelete key 1 (once):\n");
    multimap_delete(map, 1);
    multimap_print(map);
    printf("Size: %d\n\n", multimap_size(map));

    printf("Is empty? %s\n", multimap_is_empty(map) ? "yes" : "no");

    free_multimap(map);
    return 0;
}
