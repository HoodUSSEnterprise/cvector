#include "complex/complex.h"

int main(int argc, char **argv)
{
    Complex c1 = create_complex(3.0, 4.0);
    Complex c2 = create_complex(3.0, 4.0);
    Complex c3 = add_complex(c1, c2);
    print_complex(c3);
    c3 = sub_complex(c1, c2);
    print_complex(c3);
    c3 = mul_complex(c1, c2);
    print_complex(c3);
    c3 = div_complex(c1, c2);
    print_complex(c3);
    c3 = power_complex(c1, 3);
    print_complex(c3);
    printf("%s\n", is_equal_complex(c1, c2) ? "true" : "false");

    return 0;
}