#include "vector/insert_vector.h"

void insert_vectori_i(Vectori **v, size_t pos, int value)
{
    if(v == NULL || (*v) == NULL)
    {
        return;
    }
    Vectori *res = (Vectori*)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
    }
    res->len = (*v)->len + 1;
    res->data = (int*)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
    }
    if(pos > (*v)->len - 1) // 默认pos大于数组长度，直接插入到最后
    {
        memcpy(res->data, (*v)->data, sizeof(int) * (*v)->len);
        res->data[(res->len) - 1] = value;
    }
    else
    {
        for (int i = 0, j = 0; i < res->len, j < (*v)->len; i++, j++)
        {
            if(i == pos)
            {
                res->data[i] = value;
                continue;
            }
            res->data[i] = (*v)->data[j];
        }
    }
    free((*v)->data);
    free((*v));
    *v = res;
}