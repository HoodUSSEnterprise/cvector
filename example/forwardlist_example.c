#include "forwardlist/forwardlist.h"

int main(void)
{
    ForwardList *list = create_forwardlist();

    printf("Push front 3, 1, 5, 2:\n");
    push_front_forwardlist(list, 3);
    push_front_forwardlist(list, 1);
    push_front_forwardlist(list, 5);
    push_front_forwardlist(list, 2);
    print_forwardlist(list);
    printf("Size: %d\n\n", size_forwardlist(list));

    printf("Front: %d\n\n", front_forwardlist(list));

    printf("Insert 99 after position 1:\n");
    insert_after_forwardlist(list, 1, 99);
    print_forwardlist(list);
    printf("Size: %d\n\n", size_forwardlist(list));

    printf("Pop front:\n");
    pop_front_forwardlist(list);
    print_forwardlist(list);
    printf("Size: %d\n\n", size_forwardlist(list));

    printf("Erase after position 0:\n");
    erase_after_forwardlist(list, 0);
    print_forwardlist(list);
    printf("Size: %d\n\n", size_forwardlist(list));

    printf("Is empty? %s\n\n", is_empty_forwardlist(list) ? "yes" : "no");

    printf("Clear:\n");
    clear_forwardlist(list);
    printf("Is empty? %s\n", is_empty_forwardlist(list) ? "yes" : "no");
    printf("Size: %d\n", size_forwardlist(list));

    free_forwardlist(list);
    return 0;
}
