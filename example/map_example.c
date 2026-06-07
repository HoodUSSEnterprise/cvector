#include "map/map.h"

int main(void)
{
    Map *map = create_map();

    /* Insert key-value pairs */
    map_put(map, 3, 30);
    map_put(map, 1, 10);
    map_put(map, 4, 40);
    map_put(map, 2, 20);
    map_put(map, 5, 50);

    printf("After inserts:\n");
    map_print(map);
    printf("Size: %d\n\n", map_size(map));

    /* Update existing key */
    printf("Updating key 3 to 99:\n");
    map_put(map, 3, 99);
    map_print(map);
    printf("Size: %d\n\n", map_size(map));

    /* Get values */
    int *v = map_get(map, 2);
    if (v)
    {
        printf("map_get(2) = %d\n", *v);
    }

    v = map_get(map, 9);
    printf("map_get(9) = %s\n\n", v ? "found" : "NULL");

    /* Contains */
    printf("Contains 4? %s\n", map_contains(map, 4) ? "yes" : "no");
    printf("Contains 7? %s\n\n", map_contains(map, 7) ? "yes" : "no");

    /* Delete */
    printf("Deleting keys 1, 4:\n");
    map_delete(map, 1);
    map_delete(map, 4);
    map_print(map);
    printf("Size: %d\n", map_size(map));

    free_map(map);
    return 0;
}
