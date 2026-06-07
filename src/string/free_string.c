#include "string/free_string.h"

void free_string(MyString *str)
{
    free(str->buffer);
    str->buffer = NULL;
    str->len = 0;
}