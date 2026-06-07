#include "queue/queue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 65001");
    printf("=== 队列测试 ===\n\n");

    // 创建队列
    Queue *q = create_queue();

    // 入队
    printf("入队: 10, 20, 30\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    print_queue(q);
    printf("队列大小: %d\n\n", get_queue_size(q));

    // 查看队头
    int val;
    front(q, &val);
    printf("队头元素: %d\n\n", val);

    // 出队
    printf("出队: ");
    while (dequeue(q, &val) == 0)
    {
        printf("%d ", val);
    }
    printf("\n");

    printf("队列是否为空: %s\n", is_empty_queue(q) ? "是" : "否");

    // 清理
    free_queue(q);

    return 0;
}