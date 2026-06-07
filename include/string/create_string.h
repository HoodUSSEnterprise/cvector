#ifndef CREATE_STRING_H
#define CREATE_STRING_H

#include "string/base_string.h"

MyString *create_string_char(const char *str);

MyString *create_string_string(const MyString *str);

#define create_string(str) _Generic((str), \
    char *: create_string_char,            \
    MyString *: create_string_string)(str)

#endif // CREATE_STRING_H