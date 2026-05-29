# CVector — C Vector/Matrix/Complex Library

A C11 library providing **vector**, **matrix**, and **complex number** types with a full set of linear algebra operations. Uses `_Generic` for type-generic APIs — one function name works across `int`, `float`, `double`, and `Complex`.

## Features

### Complex Numbers (`Complex`)
- Arithmetic: `add`, `sub`, `mul`, `div`, `power`
- Comparison: `is_equal`
- Pretty printing

### Vectors (fixed-size 2D/tailored and dynamic arrays)
- **Fixed-size**: `Vector2i`, `Vector2f`, `Vector2d`, `Vector2c` (2-component vectors)
- **Dynamic**: `Vectori`, `Vectorf`, `Vectord`, `Vectorc` (arbitrary-length)
- Operations: `add`, `sub`, `mul`, `norm` (Lp-norm), `print`
- Element: `push_back`, `pop`, `insert`, `remove` (by value or array), `replace`, `find`, `reverse`

### Matrices (`MatrixI`, `MatrixF`, `MatrixD`, `MatrixC`)
- **Create**: from arrays (`int*`, `float*`, `double*`, `Complex*`), auto-converting between types
- **Special matrices**: `identity`, `zero`, `eye`, `diag`
- **Random**: `random_matrix`, `random_col_vector`, `random_row_vector`
- **Arithmetic**: `add`, `sub`, `mul`, `scalar_mul`, `pow` (including negative = inverse^n)
- **Linear algebra**:
  - Transpose, determinant, inverse
  - Rank, trace
  - Minor, cofactor, adjugate
  - LU decomposition (Doolittle, Crout, Cholesky, LDU)
  - QR decomposition (Gram-Schmidt, Householder)
  - Eigenvalues (QR iteration) and eigenvectors
- **Manipulation**: `copy`, `cat` (concatenate), `remove` rows/columns, `replace` elements
- **Extract**: column vectors, diagonal elements
- **Search**: `find` element (returns position), `remove_matrix` row/column
- **Check**: `is_identity`, `is_inv` (invertible), `is_orth` (orthogonal), `is_positive` (definite), `can_lu_decomposition`
- **Compare**: `is_equal` across different types
- **Print**: formatted matrix output

### Type-Generic Macros
All major operations use C11 `_Generic` — call `add_matrix(m1, m2)` regardless of element type.

| Macro | Auto-detects |
|-------|-------------|
| `create_matrixi/f/d/c` | input data pointer type |
| `add_matrix`, `sub_matrix`, `mul_matrix` | both operands |
| `scalar_mul_matrix` | matrix and scalar |
| `cat_matrix` | both operands |
| `det_matrix`, `inv_matrix`, `pow_matrix` | input |
| `transpose_matrix`, `copy_matrix` | input |
| `print_matrix`, `free_matrix` | input |
| `is_equal_matrix` | both operands |
| `find_matrix`, `replace_matrix` | input |
| `remove_matrix` | input |

## Quick Start

```c
#include "matrix/matrix.h"

int main(void)
{
    double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    MatrixD *m = create_matrixd(3, 3, data, 9);

    printf("A =\n");
    print_matrix(m);

    printf("det(A) = %lf\n", det_matrix(m));
    printf("trace(A) = %lf\n", trace_matrix(m));

    MatrixD *inv = inv_matrix(m);
    printf("A^(-1) =\n");
    print_matrix(inv);

    // A * A^(-1) should be identity
    MatrixD *check = mul_matrix(m, inv);
    print_matrix(check);

    free_matrix(m);
    free_matrix(inv);
    free_matrix(check);
    return 0;
}
```

## Building

### With CMake
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Targets
| Target | Description |
|--------|-------------|
| `complex_lib` | Complex number library |
| `vector_lib` | Vector library (depends on complex_lib) |
| `matrix_lib` | Matrix library (depends on complex_lib) |
| `test_program_complex` | Complex number example |
| `test_program_vector` | Vector example |
| `test_program_matrix` | Matrix example |

## Project Structure

```
├── CMakeLists.txt
├── include/
│   ├── complex/       # Complex number API
│   ├── vector/        # Vector API
│   ├── matrix/        # Matrix API (includes all sub-headers)
│   └── tools/         # Utility functions
├── src/
│   ├── complex/       # Complex number implementation
│   ├── vector/        # Vector implementation
│   ├── matrix/        # Matrix implementation
│   └── tools/         # Utility implementation
└── example/
    ├── complex_example.c
    ├── vector_example.c
    └── matrix_example.c
```

## Requirements

- C11 compiler (for `_Generic` support)
- CMake 3.10+
- Standard C library only (no external dependencies)
