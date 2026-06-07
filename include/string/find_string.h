#ifndef FIND_STRING_H
#define FIND_STRING_H

#include "string/base_string.h"

int index_of(MyString *self, const char *str)
{
    char *pos = strstr(self->buffer, str);
    return pos ? (pos - self->buffer) : -1;
}

int last_index_of(MyString *self, const char *str)
{
    char *pos = strrchr(self->buffer, str[0]);
    return pos ? (pos - self->buffer) : -1;
}

#endif // FIND_STRING_H