#include "tools/max_min.h"
#include <limits.h>
#define ERROR __INT_MAX__

int maxi_elem(int a, int b)
{
    return a > b ? a : b;
}

float maxf_elem(float a, float b)
{
    return a > b ? a : b;
}

double maxd_elem(double a, double b)
{
    return a > b ? a : b;
}

int mini_elem(int a, int b)
{
    return a < b ? a : b;
}

float minf_elem(float a, float b)
{
    return a < b ? a : b;
}

double mind_elem(double a, double b)
{
    return a < b ? a : b;
}

int maxi_arr(int *arr, size_t len)
{
    if (len == 0)
    {
        return ERROR;
    }

    int max_val = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    return max_val;
}

float maxf_arr(float *arr, size_t len)
{
    if (len == 0)
    {
        return ERROR;
    }

    int max_val = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    return max_val;
}

double maxd_arr(double *arr, size_t len)
{
    if (len == 0)
    {
        return ERROR;
    }

    int max_val = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    return max_val;
}

int mini_arr(int *arr, size_t len)
{
    if (len == 0)
    {
        return ERROR;
    }

    int min_val = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    return min_val;
}

float minf_arr(float *arr, size_t len)
{
    if (len == 0)
    {
        return ERROR;
    }

    int min_val = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    return min_val;
}

double mind_arr(double *arr, size_t len)
{
    if (len == 0)
    {
        return ERROR;
    }

    int min_val = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    return min_val;
}