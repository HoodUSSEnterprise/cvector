#include "deque/deque.h"
#include <stdio.h>
#include <stdlib.h>

void print_deque(Deque *d)
{
    if (!d || is_empty_deque(d))
    {
        printf("双端队列为空\n");
        return;
    }

    Deque *temp = create_deque();
    int val;

    printf("双端队列内容: ");
    while (pop_front(d, &val) == 0)
    {
        printf("%d ", val);
        push_rear(temp, val);
    }

    while (pop_front(temp, &val) == 0)
    {
        push_rear(d, val);
    }

    free_deque(temp);
    printf("\n");
}

int main()
{
    system("chcp 65001");
    printf("=== 双端队列测试 ===\n\n");

    // 创建双端队列
    Deque *d = create_deque();

    // 从后面插入
    printf("从后面插入: 10, 20, 30\n");
    push_rear(d, 10);
    push_rear(d, 20);
    push_rear(d, 30);
    print_deque(d);

    // 从前面插入
    printf("从前面插入: 5, 1\n");
    push_front(d, 5);
    push_front(d, 1);
    print_deque(d);

    printf("双端队列大小: %d\n\n", get_deque_size(d));

    // 查看两端
    int val;
    front(d, &val);
    printf("队头: %d\n", val);
    rear(d, &val);
    printf("队尾: %d\n\n", val);

    // 从前面弹出
    pop_front(d, &val);
    printf("弹出队头: %d\n", val);
    print_deque(d);

    // 从后面弹出
    pop_rear(d, &val);
    printf("弹出队尾: %d\n", val);
    print_deque(d);

    printf("双端队列大小: %d\n\n", get_deque_size(d));

    // 清空
    clear_deque(d);
    printf("清空后大小: %d\n", get_deque_size(d));

    // 清理
    free_deque(d);

    return 0;
}