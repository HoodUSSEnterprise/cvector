#ifndef MAX_MIN_H
#define MAX_MIN_H

#include <stdio.h>

int maxi_elem(int a, int b);

float maxf_elem(float a, float b);

double maxd_elem(double a, double b);

int mini_elem(int a, int b);

float minf_elem(float a, float b);

double mind_elem(double a, double b);

int maxi_arr(int *arr, size_t len);

float maxf_arr(float *arr, size_t len);

double maxd_arr(double *arr, size_t len);

int mini_arr(int *arr, size_t len);

float minf_arr(float *arr, size_t len);

double mind_arr(double *arr, size_t len);

#define min(x, y) _Generic((x), \
    int: mini_elem,             \
    float: minf_elem,           \
    double: mind_elem,          \
    int *: mini_arr,            \
    float *: minf_arr,          \
    double *: mind_arr)(x, y)

#define max(x, y) _Generic((x), \
    int: maxi_elem,             \
    float: maxf_elem,           \
    double: maxd_elem,          \
    int *: maxi_arr,            \
    float *: maxf_arr,          \
    double *: maxd_arr)(x, y)

#endif // MAX_MIN_H