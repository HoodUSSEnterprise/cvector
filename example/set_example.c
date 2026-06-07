#include "set/set.h"

int main(void)
{
    Set *set = create_set();

    int vals[] = {5, 3, 8, 1, 4, 7, 9, 2, 6};
    int n = sizeof(vals) / sizeof(vals[0]);

    printf("Inserting:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vals[i]);
        set_insert(set, vals[i]);
    }
    printf("\n");

    printf("Set contents: ");
    set_print(set);
    printf("Size: %d  Min: %d  Max: %d\n\n", set_size(set), set_min(set), set_max(set));

    printf("Contains 4? %s\n", set_contains(set, 4) ? "yes" : "no");
    printf("Contains 0? %s\n\n", set_contains(set, 0) ? "yes" : "no");

    printf("Deleting 3, 8\n");
    set_delete(set, 3);
    set_delete(set, 8);
    set_print(set);
    printf("Size after delete: %d\n\n", set_size(set));

    /* Duplicate insert should be ignored */
    printf("Inserting 5 again (duplicate):\n");
    set_insert(set, 5);
    set_print(set);
    printf("Size: %d\n", set_size(set));

    free_set(set);
    return 0;
}
