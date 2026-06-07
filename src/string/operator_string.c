#include "string/operator_string.h"

void append_char(MyString **self, const char *str)
{
    if (self == NULL || *self == NULL || (*self)->buffer == NULL || str == NULL)
    {
        fprintf(stderr, "Invalid parameters\n");
        return;
    }

    size_t new_len = (*self)->len + strlen(str);
    char *new_buffer = (char *)malloc(new_len + 1); // +1 for '\0'
    if (new_buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Copy original
    strcpy(new_buffer, (*self)->buffer);
    // Append new string
    strcat(new_buffer, str);

    // Free old buffer
    free((*self)->buffer);
    // Update structure
    (*self)->buffer = new_buffer;
    (*self)->len = new_len;
}

void append_string(MyString **self, const MyString *str)
{
    if (self == NULL || *self == NULL || (*self)->buffer == NULL || str == NULL || str == NULL || str->buffer == NULL)
    {
        fprintf(stderr, "Invalid parameters\n");
        return;
    }

    size_t new_len = (*self)->len + str->len;
    char *new_buffer = (char *)malloc(new_len + 1); // +1 for '\0'
    if (new_buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Copy original
    strcpy(new_buffer, (*self)->buffer);
    // Append new string
    strcat(new_buffer, str);

    // Free old buffer
    free((*self)->buffer);
    // Update structure
    (*self)->buffer = new_buffer;
    (*self)->len = new_len;
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