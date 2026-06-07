#ifndef OPERATE_STRING_H
#define OPERATE_STRING_H

#include "string/base_string.h"
#include <stdbool.h>

void append_char(MyString *string, const char *str);

void append_string(MyString *string, const MyString *str);

bool equals_char(MyString *self, const char *str);

bool equals_string(MyString *self, const MyString *str);

int compare_char(MyString *self, const char *str);

int compare_string(MyString *self, const MyString *str);

size_t size(MyString *self);

size_t string_len(MyString *self);

bool empty(MyString *self);

#define append(string, str) _Generic((str), \
    char *: append_char,                    \
    MyString *: append_string)(string, str)

#define compare(string, str) _Generic((str), \
    char *: compare_char,                    \
    MyString *: compare_string)(string, str)

#define equals(string, str) _Generic((str), \
    char *: equals_char,                    \
    MyString *: equals_string)(string, str)

#endif // OPERATE_STRING_H