#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front; // 队头
    QueueNode *rear;  // 队尾
    int size;
} Queue;

Queue *create_queue(void);
void free_queue(Queue *queue);
int enqueue(Queue *queue, int data);  // 入队
int dequeue(Queue *queue, int *data); // 出队
int front(Queue *queue, int *data);   // 查看队头
int is_empty_queue(Queue *queue);
int get_queue_size(Queue *queue);
void clear_queue(Queue *queue);

#endif