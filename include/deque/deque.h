#ifndef DEQUE_H
#define DEQUE_H

typedef struct DequeNode
{
    int data;
    struct DequeNode *prev;
    struct DequeNode *next;
} DequeNode;

typedef struct
{
    DequeNode *front;
    DequeNode *rear;
    int size;
} Deque;

Deque *create_deque(void);
void free_deque(Deque *deque);

// 从前面插入删除
int push_front(Deque *deque, int data);
int pop_front(Deque *deque, int *data);

// 从后面插入删除
int push_rear(Deque *deque, int data);
int pop_rear(Deque *deque, int *data);

// 查看
int front(Deque *deque, int *data);
int rear(Deque *deque, int *data);

int is_empty_deque(Deque *deque);
int get_deque_size(Deque *deque);
void clear_deque(Deque *deque);
// 打印
void print_deque(Deque *deque);
void print_deque_reverse(Deque *deque);
#endif