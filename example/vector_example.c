// #define DEBUG 1
#include "vector/vector.h"

int main(void)
{
    Complex v1 = {3, 4};
    Complex v2 = {5, 6};
    Complex v3 = {7, 8};
    Vector2c *v4 = create_vec2(v1, v2);
    Vector2c *v5 = create_vec2(v1, v3);
    Vector2c *v6 = add_vec(v4, v5);
    Vector2i *v7 = create_vec2(3, 6);
    Vector2c *v8 = add_vec(v4, v7);
    print_vec(v4);
    print_vec(v6);
    print_vec(v8);
    double norm = norm_vec(v4, 2);
    printf("%lf\n", norm);
    Complex data[5] = {v1, v2, v3, v2, v3};
    Vectorc *v = create_vec(data, 5);
    // Complex remove[2] = {v1, v2};
    int da[5] = {1, 2, 3, 4, 5};

    int re[2] = {1, 2};
    Vectori *vint = create_vec(da, 5);
    Vectori *vone = remove_elem(vint, 1);
    Vectori *varr = remove_arr(vint, re, 2);
    print_vec(v);
    print_vec(vone);
    print_vec(varr);
    Vectori *vreplace = replace_elem(vint, 2, 5);
    print_vec(vreplace);
    int old_arr[2] = {1, 2};
    int new_arr[2] = {3, 4};
    Vectori *vreplacearr = replace_arr(vint, old_arr, new_arr, 2);
    print_vec(vreplacearr);
    return 0;
}
