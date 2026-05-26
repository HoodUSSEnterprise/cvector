#include "vector/push_back_vector.h"

void push_back_vectori_i(Vectori **v, int push_number)
{
    Vectori *res = (Vectori*)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    res->len = (*v)->len + 1;
    res->data = (int*)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    size_t i;
    for (i = 0; i < res->len - 1; i++)
    {
        res->data[i] = (*v)->data[i];
    }
    res->data[i] = push_number;
    free((*v)->data);
    free((*v));
    *v = res;
}