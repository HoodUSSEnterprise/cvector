#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 简单函数1：整数入栈出栈
void test_int()
{
    printf("=== 整数测试 ===\n");
    Stack *s = create_stack();

    int a = 10, b = 20, c = 30;
    push(s, &a);
    push(s, &b);
    push(s, &c);

    int *p;
    pop(s, (void **)&p);
    printf("出栈: %d\n", *p);
    pop(s, (void **)&p);
    printf("出栈: %d\n", *p);

    free_stack(s);
}

// 简单函数2：字符串入栈出栈
void test_string()
{
    printf("\n=== 字符串测试 ===\n");
    Stack *s = create_stack();

    char *str1 = "Hello";
    char *str2 = "World";
    push(s, str1);
    push(s, str2);

    char *str;
    pop(s, (void **)&str);
    printf("出栈: %s\n", str);
    pop(s, (void **)&str);
    printf("出栈: %s\n", str);

    free_stack(s);
}

// 简单函数3：查看栈顶
void test_top()
{
    printf("\n=== 查看栈顶测试 ===\n");
    Stack *s = create_stack();

    int x = 100;
    push(s, &x);

    int *p;
    top(s, (void **)&p);
    printf("栈顶: %d\n", *p);
    printf("栈大小: %d\n", get_stack_size(s));

    free_stack(s);
}

int main()
{
    system("chcp 65001");
    test_int();
    test_string();
    test_top();
    return 0;
}