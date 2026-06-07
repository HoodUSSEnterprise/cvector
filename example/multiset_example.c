#include "multiset/multiset.h"

int main(void)
{
    MultiSet *set = create_multiset();

    int vals[] = {5, 3, 8, 3, 5, 1, 5, 9, 3};
    int n = sizeof(vals) / sizeof(vals[0]);

    printf("Inserting:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vals[i]);
        multiset_insert(set, vals[i]);
    }
    printf("\n");

    printf("Inorder: ");
    multiset_print(set);
    printf("Size: %d  Min: %d  Max: %d\n\n", multiset_size(set), multiset_min(set), multiset_max(set));

    printf("Count of 5: %d\n", multiset_count(set, 5));
    printf("Count of 3: %d\n", multiset_count(set, 3));
    printf("Count of 1: %d\n", multiset_count(set, 1));
    printf("Contains 8? %s\n\n", multiset_contains(set, 8) ? "yes" : "no");

    printf("Delete 5 (once):\n");
    multiset_delete(set, 5);
    printf("Inorder: ");
    multiset_print(set);
    printf("Size: %d  Count of 5: %d\n\n", multiset_size(set), multiset_count(set, 5));

    printf("Delete 3 (twice):\n");
    multiset_delete(set, 3);
    multiset_delete(set, 3);
    printf("Inorder: ");
    multiset_print(set);
    printf("Size: %d\n", multiset_size(set));

    printf("Is empty? %s\n", multiset_is_empty(set) ? "yes" : "no");

    free_multiset(set);
    return 0;
}
