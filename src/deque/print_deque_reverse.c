#include "deque/deque.h"
#include <stdio.h>

void print_deque_reverse(Deque *deque)
{
    if (!deque || is_empty_deque(deque))
    {
        printf("双端队列为空\n");
        return;
    }

    Deque *temp = create_deque();
    int val;

    // 从后面弹出并保存
    while (pop_rear(deque, &val) == 0)
    {
        printf("%d ", val);
        push_front(temp, val);
    }

    // 恢复原队列
    while (pop_rear(temp, &val) == 0)
    {
        push_front(deque, val);
    }

    free_deque(temp);
    printf("\n");
}