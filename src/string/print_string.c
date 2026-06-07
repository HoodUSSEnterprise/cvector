#include "string/print_string.h"

void print_string(MyString *str)
{
    if (str == NULL || str->buffer == NULL)
    {
        printf("Invalid param\n");
        return;
    }
    printf("%s\n", str->buffer);
}