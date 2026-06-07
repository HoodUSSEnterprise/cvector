#include "stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_int()
{
    printf("=== 整数测试 ===\n");
    Stack *s = create_stack();

    int a = 10, b = 20, c = 30;
    push(s, a);
    push(s, b);
    push(s, c);

    print_stack(s);

    int p = 0;
    pop(s, &p);
    printf("出栈: %d\n", p);
    pop(s, &p);
    printf("出栈: %d\n", p);

    free_stack(s);
}

int main()
{
    system("chcp 65001");
    test_int();
    return 0;
}