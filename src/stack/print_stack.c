#include "stack/print_stack.h"

void print_stack(Stack *stack)
{
    if (!stack || is_empty_stack(stack))
    {
        printf("栈为空\n");
        return;
    }

    // 创建临时栈来反转顺序
    Stack *temp = create_stack_int();

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