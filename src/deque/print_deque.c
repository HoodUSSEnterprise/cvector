#include "deque/deque.h"
#include <stdio.h>

void print_deque(Deque *deque)
{
    if (!deque || is_empty_deque(deque))
    {
        printf("双端队列为空\n");
        return;
    }

    Deque *temp = create_deque();
    int val;

    // 弹出并保存到临时队列
    while (pop_front(deque, &val) == 0)
    {
        printf("%d ", val);
        push_rear(temp, val);
    }

    // 恢复原队列
    while (pop_front(temp, &val) == 0)
    {
        push_rear(deque, val);
    }

    free_deque(temp);
    printf("\n");
}