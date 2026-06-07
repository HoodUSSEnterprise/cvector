#include "string/mystring.h"

int main(void)
{
    MyString *my_str1 = create_string("Hello world");
    MyString *my_str2 = create_string(my_str1);
    printf("len of my_str1 = %zu\n", string_len(my_str1));
    append(my_str1, "He");
    print_string(my_str1);
    if (equals(my_str1, my_str2))
    {
        printf("Equals\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}