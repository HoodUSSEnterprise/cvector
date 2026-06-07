#ifndef STACK_H
#define STACK_H

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
    int size;
} Stack;

Stack *create_stack(void);
void free_stack(Stack *stack);
int push(Stack *stack, int data);
int pop(Stack *stack, int *data);
int top(Stack *stack, int *data);
int is_empty_stack(Stack *stack);
int get_stack_size(Stack *stack);
void clear_stack(Stack *stack);

#endif // STACK_H