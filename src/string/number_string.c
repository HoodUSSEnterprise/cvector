#include "string/number_string.h"

int stoi(MyString *self)
{
    if (self == NULL || self->buffer == NULL)
    {
        fprintf(stderr, "stoi: invalid MyString\n");
        exit(EXIT_FAILURE);
    }

    char *endptr;
    errno = 0;
    long value = strtol(self->buffer, &endptr, 10);

    // 检查是否转换了任何字符
    if (endptr == self->buffer)
    {
        fprintf(stderr, "stoi: no conversion\n");
        exit(EXIT_FAILURE);
    }

    // 检查是否还有未转换的字符（可选：允许空格）
    while (*endptr != '\0')
    {
        if (!isspace((unsigned char)*endptr))
        {
            fprintf(stderr, "stoi: invalid trailing characters\n");
            exit(EXIT_FAILURE);
        }
        endptr++;
    }

    // 检查溢出
    if ((value == LONG_MAX || value == LONG_MIN) && errno == ERANGE)
    {
        fprintf(stderr, "stoi: out of range\n");
        exit(EXIT_FAILURE);
    }

    // 检查 int 范围
    if (value < INT_MIN || value > INT_MAX)
    {
        fprintf(stderr, "stoi: out of int range\n");
        exit(EXIT_FAILURE);
    }

    return (int)value;
}

float stof(MyString *self)
{
    if (self == NULL || self->buffer == NULL)
    {
        fprintf(stderr, "stof: invalid MyString\n");
        exit(EXIT_FAILURE);
    }

    char *endptr;
    errno = 0;
    float value = strtof(self->buffer, &endptr);

    // 检查是否转换了任何字符
    if (endptr == self->buffer)
    {
        fprintf(stderr, "stof: no conversion\n");
        exit(EXIT_FAILURE);
    }

    // 检查是否还有未转换的字符（可选：允许空格）
    while (*endptr != '\0')
    {
        if (!isspace((unsigned char)*endptr))
        {
            fprintf(stderr, "stof: invalid trailing characters\n");
            exit(EXIT_FAILURE);
        }
        endptr++;
    }

    // 检查溢出
    if (errno == ERANGE)
    {
        fprintf(stderr, "stof: out of range\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

double stod(MyString *self)
{
    if (self == NULL || self->buffer == NULL)
    {
        fprintf(stderr, "stod: invalid MyString\n");
        exit(EXIT_FAILURE);
    }

    char *endptr;
    errno = 0;
    double value = strtod(self->buffer, &endptr);

    // 检查是否转换了任何字符
    if (endptr == self->buffer)
    {
        fprintf(stderr, "stod: no conversion\n");
        exit(EXIT_FAILURE);
    }

    // 检查是否还有未转换的字符（可选：允许空格）
    while (*endptr != '\0')
    {
        if (!isspace((unsigned char)*endptr))
        {
            fprintf(stderr, "stod: invalid trailing characters\n");
            exit(EXIT_FAILURE);
        }
        endptr++;
    }

    // 检查溢出
    if (errno == ERANGE)
    {
        fprintf(stderr, "stod: out of range\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

MyString *to_string_int(int number)
{
    // 先计算需要多少空间
    int len = snprintf(NULL, 0, "%d", number);
    if (len < 0)
    {
        return NULL;
    }

    MyString *result = (MyString *)malloc(sizeof(MyString));
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    result->buffer = (char *)malloc(len + 1);
    if (result->buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(result);
        return NULL;
    }

    snprintf(result->buffer, len + 1, "%d", number);
    result->len = len;
    return result;
}

MyString *to_string_float(float number)
{
    int len = snprintf(NULL, 0, "%g", number); // %g 自动选择格式
    if (len < 0)
    {
        return NULL;
    }

    MyString *result = (MyString *)malloc(sizeof(MyString));
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    result->buffer = (char *)malloc(len + 1);
    if (result->buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(result);
        return NULL;
    }

    snprintf(result->buffer, len + 1, "%g", number);
    result->len = len;
    return result;
}

MyString *to_string_double(double number)
{
    int len = snprintf(NULL, 0, "%g", number);
    if (len < 0)
    {
        return NULL;
    }

    MyString *result = (MyString *)malloc(sizeof(MyString));
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    result->buffer = (char *)malloc(len + 1);
    if (result->buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(result);
        return NULL;
    }

    snprintf(result->buffer, len + 1, "%g", number);
    result->len = len;
    return result;
}