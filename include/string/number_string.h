#ifndef NUMBER_STRING_H
#define NUMBER_STRING_H

#include "string/base_string.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>

int stoi(MyString *self);

float stof(MyString *self);

double stod(MyString *self);

MyString *to_string_int(int number);

MyString *to_string_float(float number);

MyString *to_string_double(double number);

#define to_string(number) _Generic((number), \
    int: to_string_int,                      \
    float: to_string_float,                  \
    double: to_string_double)(number)

#endif // NUMBER_STRING_H