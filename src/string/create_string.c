#include "string/create_string.h"

MyString *create_string_char(const char *str)
{
    if (str == NULL)
    {
        fprintf(stderr, "Invalid paraments\n");
        return NULL;
    }
    MyString *res = (MyString *)malloc(sizeof(MyString));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = strlen(str);
    res->buffer = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (res->buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    strcpy(res->buffer, str);
    return res;
}

MyString *create_string_string(const MyString *str)
{
    if (str == NULL || str->buffer == NULL)
    {
        fprintf(stderr, "Invalid paraments\n");
        return NULL;
    }
    MyString *res = (MyString *)malloc(sizeof(MyString));
    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    res->len = str->len;
    res->buffer = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (res->buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(res);
        return NULL;
    }
    strcpy(res->buffer, str->buffer);
    return res;
}