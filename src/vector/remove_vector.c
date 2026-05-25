#include "vector/remove_vector.h"
#include "vector/copy_vector.h"

Vectori *remove_vectori_elem(Vectori *v, int elem)
{
    // 先统计有多少个要删除的元素
    int count = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        if (v->data[i] == elem)
        {
            count++;
        }
    }

    // 如果没找到，返回 Nonei（假设 Nonei 是 NULL 或特殊标志）
    if (count == 0)
    {
        return Nonei;
    }

    // 如果删除后长度为 0，也返回 Nonei（或者可以返回空向量，取决于你的设计）
    if (v->len - count == 0)
    {
        return Nonei;
    }

    // 分配新向量
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len - count;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }

    // 拷贝所有不匹配的元素
    for (size_t i = 0, j = 0; i < v->len; i++)
    {
        if (v->data[i] != elem)
        {
            res->data[j++] = v->data[i];
        }
    }
    return res;
}

Vectorf *remove_vectorf_elem(Vectorf *v, float elem)
{
    // 统计要删除的元素个数（注意：浮点数比较需考虑精度）
    int count = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        if (fabs(v->data[i] - elem) < 1e-6) // 浮点数比较
        {
            count++;
        }
    }

    // 没找到
    if (count == 0)
    {
        return Nonef;
    }

    // 删除后长度为0
    if (v->len - count == 0)
    {
        return Nonef;
    }

    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len - count;
    res->data = (float *)malloc(sizeof(float) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }

    // 拷贝所有不等于 elem 的元素
    for (size_t i = 0, j = 0; i < v->len; i++)
    {
        if (fabs(v->data[i] - elem) >= 1e-6) // 不匹配才拷贝
        {
            res->data[j++] = v->data[i];
        }
    }
    return res;
}

Vectord *remove_vectord_elem(Vectord *v, double elem)
{
    // 统计要删除的元素个数
    int count = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        if (fabs(v->data[i] - elem) < 1e-6)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return Noned;
    }

    if (v->len - count == 0)
    {
        return Noned;
    }

    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len - count;
    res->data = (double *)malloc(sizeof(double) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }

    for (size_t i = 0, j = 0; i < v->len; i++)
    {
        if (fabs(v->data[i] - elem) >= 1e-12)
        {
            res->data[j++] = v->data[i];
        }
    }
    return res;
}

Vectorc *remove_vectorc_elem(Vectorc *v, Complex elem)
{
    // 统计要删除的元素个数
    int count = 0;
    for (size_t i = 0; i < v->len; i++)
    {
        if (is_equal_complex(v->data[i], elem)) // double 精度更严格
        {
            count++;
        }
    }

    if (count == 0)
    {
        return Nonec;
    }

    if (v->len - count == 0)
    {
        return Nonec;
    }

    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len - count;
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }

    for (size_t i = 0, j = 0; i < v->len; i++)
    {
        if (is_equal_complex(v->data[i], elem))
        {
            res->data[j++] = v->data[i];
        }
    }
    return res;
}

Vectori *remove_vectori_array(Vectori *v, int *array, size_t len)
{
    Vectori *res = (Vectori *)malloc(sizeof(Vectori));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len;
    res->data = (int *)malloc(sizeof(int) * res->len);
    if (res->data == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    memcpy(res->data, v->data, sizeof(int) * res->len);
    for (size_t i = 0; i < len; i++)
    {
        Vectori *temp = remove_vectori_elem(res, array[i]);
        res = (temp == Nonei ? res : temp);
    }
    return res;
}

Vectorf *remove_vectorf_array(Vectorf *v, float *array, size_t len)
{
    Vectorf *res = (Vectorf *)malloc(sizeof(Vectorf));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len;
    res->data = (float *)malloc(sizeof(float) * res->len);
    memcpy(res->data, v->data, sizeof(float) * res->len);
    for (size_t i = 0; i < len; i++)
    {
        Vectorf *temp = remove_vectorf_elem(res, array[i]);
        res = (temp == Nonef ? res : temp);
    }
    return res;
}

Vectord *remove_vectord_array(Vectord *v, double *array, size_t len)
{
    Vectord *res = (Vectord *)malloc(sizeof(Vectord));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len;
    res->data = (double *)malloc(sizeof(double) * res->len);
    memcpy(res->data, v->data, sizeof(double) * res->len);
    for (size_t i = 0; i < len; i++)
    {
        Vectord *temp = remove_vectord_elem(res, array[i]);
        res = (temp == Noned ? res : temp);
    }
    return res;
}

Vectorc *remove_vectorc_array(Vectorc *v, Complex *array, size_t len)
{
    Vectorc *res = (Vectorc *)malloc(sizeof(Vectorc));
    if (res == NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    res->len = v->len;
    res->data = (Complex *)malloc(sizeof(Complex) * res->len);
    memcpy(res->data, v->data, sizeof(Complex) * res->len);
    for (size_t i = 0; i < len; i++)
    {
        Vectorc *temp = remove_vectorc_elem(res, array[i]);
        res = (temp == Nonec ? res : temp);
    }
    return res;
}