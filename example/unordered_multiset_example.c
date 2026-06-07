#include "unordered_multiset/unordered_multiset.h"

int main(void)
{
    UnorderedMultiset *set = create_unordered_multiset();

    printf("Inserting: 5, 3, 5, 1, 3, 5, 7\n");
    unordered_multiset_insert(set, 5);
    unordered_multiset_insert(set, 3);
    unordered_multiset_insert(set, 5);
    unordered_multiset_insert(set, 1);
    unordered_multiset_insert(set, 3);
    unordered_multiset_insert(set, 5);
    unordered_multiset_insert(set, 7);

    printf("Contents: ");
    unordered_multiset_print(set);
    printf("Size: %d  Unique: %d\n\n", unordered_multiset_size(set), unordered_multiset_unique(set));

    printf("Count of 5: %d\n", unordered_multiset_count(set, 5));
    printf("Count of 3: %d\n", unordered_multiset_count(set, 3));
    printf("Count of 9: %d\n", unordered_multiset_count(set, 9));
    printf("Contains 1? %s\n\n", unordered_multiset_contains(set, 1) ? "yes" : "no");

    printf("Delete 5 (once):\n");
    unordered_multiset_delete(set, 5);
    unordered_multiset_print(set);
    printf("Size: %d  Count of 5: %d\n\n", unordered_multiset_size(set), unordered_multiset_count(set, 5));

    printf("Delete 3 (all):\n");
    unordered_multiset_delete(set, 3);
    unordered_multiset_delete(set, 3);
    unordered_multiset_print(set);
    printf("Size: %d  Unique: %d\n", unordered_multiset_size(set), unordered_multiset_unique(set));

    free_unordered_multiset(set);
    return 0;
}
