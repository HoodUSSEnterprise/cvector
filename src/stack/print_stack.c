#include "stack/print_stack.h"

void print_stack_int(StackInt *stack)
{
    if (!stack || is_empty_stack(stack))
    {
        printf("栈为空\n");
        return;
    }

    // 创建临时栈来反转顺序
    StackInt *temp = create_stack_int();

    // 弹出所有元素到临时栈
    int val;
    while (pop(stack, &val) == 0)
    {
        push(temp, val);
    }

    // 打印并恢复原栈
    printf("栈底 -> 栈顶: ");
    while (pop(temp, &val) == 0)
    {
        printf("%d ", val);
        push(stack, val); // 恢复回原栈
    }
    printf("\n");

    free_stack(temp);
}

void print_stack_float(StackFloat *stack)
{
    if (!stack || is_empty_stack(stack))
    {
        printf("栈为空\n");
        return;
    }

    // 创建临时栈来反转顺序
    StackFloat *temp = create_stack_float();

    // 弹出所有元素到临时栈
    float val;
    while (pop(stack, &val) == 0)
    {
        push(temp, val);
    }

    // 打印并恢复原栈
    printf("栈底 -> 栈顶: ");
    while (pop(temp, &val) == 0)
    {
        printf("%f ", val);
        push(stack, val); // 恢复回原栈
    }
    printf("\n");

    free_stack(temp);
}

void print_stack_double(StackDouble *stack)
{
    if (!stack || is_empty_stack(stack))
    {
        printf("栈为空\n");
        return;
    }

    // 创建临时栈来反转顺序
    StackDouble *temp = create_stack_double();

    // 弹出所有元素到临时栈
    double val;
    while (pop(stack, &val) == 0)
    {
        push(temp, val);
    }

    // 打印并恢复原栈
    printf("栈底 -> 栈顶: ");
    while (pop(temp, &val) == 0)
    {
        printf("%lf ", val);
        push(stack, val); // 恢复回原栈
    }
    printf("\n");

    free_stack(temp);
}