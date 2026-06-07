#include "string/operator_string.h"

void append_char(MyString *self, const char *str)
{
    size_t new_len = self->len + strlen(str);
    char *new_buf = realloc(self->buffer, new_len + 1);
    if (new_buf == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    self->buffer = new_buf;
    strcat(self->buffer, str);
    self->len = new_len;
}

void append_string(MyString *self, const MyString *str)
{
    size_t new_len = self->len + str->len;
    char *new_buf = realloc(self->buffer, new_len + 1);
    if (new_buf == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    self->buffer = new_buf;
    strcat(self->buffer, str->buffer);
    self->len = new_len;
}

bool equals_char(MyString *self, const char *str)
{
    return strcmp(self->buffer, str) == 0;
}

int compare_char(MyString *self, const char *str)
{
    return strcmp(self->buffer, str);
}

bool equals_string(MyString *self, const MyString *str)
{
    return strcmp(self->buffer, str->buffer) == 0;
}

int compare_string(MyString *self, const MyString *str)
{
    return strcmp(self->buffer, str->buffer);
}

size_t size(MyString *self)
{
    return self->len;
}

size_t string_len(MyString *self)
{
    return self->len;
}

bool empty(MyString *self)
{
    return self->len == 0;
}