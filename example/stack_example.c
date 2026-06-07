#include "stack/stack.h"
#include <stdio.h>
#include <string.h>

int main()
{
    Stack *back_stack = create_stack();    // 后退栈
    Stack *forward_stack = create_stack(); // 前进栈
    char current_page[100] = "首页";

    printf("=== 浏览器历史记录演示 ===\n\n");

    // 访问新页面
    printf("访问新页面: 百度\n");
    push(back_stack, (int)strdup("百度"));
    printf("访问新页面: 谷歌\n");
    push(back_stack, (int)strdup("谷歌"));
    printf("访问新页面: GitHub\n");
    push(back_stack, (int)strdup("GitHub"));
    printf("当前页面: GitHub\n\n");

    // 后退操作
    int page;
    printf("后退操作:\n");
    if (pop(back_stack, &page) == 0)
    {
        push(forward_stack, (int)strdup("GitHub"));
        printf("后退到: %s\n", (char *)page);
        free((void *)page);
    }

    if (pop(back_stack, &page) == 0)
    {
        push(forward_stack, (int)strdup("谷歌"));
        printf("后退到: %s\n", (char *)page);
        free((void *)page);
    }
    printf("\n");

    // 前进操作
    printf("前进操作:\n");
    if (pop(forward_stack, &page) == 0)
    {
        push(back_stack, (int)strdup((char *)page));
        printf("前进到: %s\n", (char *)page);
        free((void *)page);
    }
    printf("\n");

    // 清理
    free_stack(back_stack);
    free_stack(forward_stack);

    return 0;
}