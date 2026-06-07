#ifndef BASE_STRING_H
#define BASE_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyString
{
    char *buffer;
    size_t len;
} MyString;

#endif // BASE_STRING_H