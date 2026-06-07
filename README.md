# CVector — C Vector/Matrix/Complex/String/Data-Structures Library

A C11 library providing **complex numbers**, **vectors** (fixed-size 2D/3D & dynamic), **matrices** (with full linear algebra), **strings**, **stacks**, **queues**, **deques**, and **hash tables**. Uses `_Generic` for type-generic APIs — one function name works across `int`, `float`, `double`, and `Complex`.

## Modules

### Complex Numbers (`Complex`)
Real/imaginary pairs with full arithmetic support.

| Type | Header |
|------|--------|
| `Complex` | `complex/complex.h` |

- **Arithmetic**: `add_complex`, `sub_complex`, `mul_complex`, `div_complex`, `power_complex`
- **Comparison**: `is_equal_complex`
- **Create/Free**: `create_complex`, `copy_complex`, `free_complex`
- **Print**: `print_complex`

### Vectors (Fixed-size 2D/3D & Dynamic Arrays)

| Type | Description | Header |
|------|-------------|--------|
| `Vector2i/f/d/c` | 2-component vector | `vector/vector.h` |
| `Vector3i/f/d/c` | 3-component vector | `vector/vector.h` |
| `Vectori/f/d/c` | Dynamic array | `vector/vector.h` |

**Fixed-size operations**: `add_vec`, `sub_vec`, `mul_vec`, `norm_vec` (Lp-norm), `print_vec`
**Dynamic array operations**:
- `create_vec`, `free_vec`, `print_vec`
- `push_back_vec`, `pop_vec`, `insert_vec`
- `remove_elem`, `remove_arr`, `replace_elem`, `replace_arr`
- `find_vec`, `reverse_vec`
- `copy_vec`

### Matrices (`MatrixI`, `MatrixF`, `MatrixD`, `MatrixC`)
Full linear algebra with type-generic macros.

| Type | Header |
|------|--------|
| `MatrixI` (int), `MatrixF` (float), `MatrixD` (double), `MatrixC` (Complex) | `matrix/matrix.h` |

**Create**: from arrays (`int*`/`float*`/`double*`/`Complex*`) with auto type conversion, plus `identity_matrix`, `zero_matrix`, `eye_matrix`, `diag_matrix`, `random_matrix`, `random_col_vector`, `random_row_vector`
**Arithmetic**: `add_matrix`, `sub_matrix`, `mul_matrix`, `scalar_mul_matrix`, `pow_matrix` (supports negative exponent = inverse^n)
**Linear algebra**: `transpose_matrix`, `det_matrix`, `inv_matrix`, `rank_matrix`, `trace_matrix`, `minor_matrix`, `cofactor_matrix`, `adjugate_matrix`
**Decompositions**:
- LU: `doolittle_matrixd`, `crout_matrixd`, `cholesky_matrixd`, `ldu_matrixd`, `can_lu_decomposition`
- QR: `qr_gs_matrixd/c`, `qr_householder_matrixd/c`, `gram_schmidt_matrixd/c`
- Eigen: `eigenvalue_matrixd/c`, `eigenvector_matrixd`
**Manipulation**: `copy_matrix`, `cat_matrix` (concatenate along axis), `remove_matrix` (row/col), `replace_matrix`
**Extract**: `col_vector_matrix`, `get_diag_matrix`
**Search**: `find_matrix` (returns `Pos` struct)
**Check**: `is_identity_matrix`, `is_inv_matrix`, `is_orth_matrix`, `is_positive_matrix`
**Compare**: `is_equal_matrix` (cross-type)
**Print**: `print_matrix`

### String (`MyString`)
Dynamic string type with common operations.

| Type | Header |
|------|--------|
| `MyString` | `string/mystring.h` |

- **Create/Free**: `create_string` (from `char*` or `MyString*`), `free_string`
- **Manipulation**: `append` (`char*` or `MyString*`), `size`, `string_len`, `empty`
- **Comparison**: `equals` (`char*` or `MyString*`), `compare`
- **Search**: `index_of`, `last_index_of`
- **Conversion**: `stoi`, `stof`, `stod`, `to_string` (`int`/`float`/`double`)
- **Print**: `print_string`

### Stack
Linked-list based stack (int data).

| Type | Header |
|------|--------|
| `Stack` | `stack/stack.h` |

- `create_stack`, `free_stack`, `clear_stack`
- `push`, `pop`, `top`
- `is_empty_stack`, `get_stack_size`
- `print_stack`

### Queue
Linked-list based queue (int data).

| Type | Header |
|------|--------|
| `Queue` | `queue/queue.h` |

- `create_queue`, `free_queue`, `clear_queue`
- `enqueue`, `dequeue`, `front`
- `is_empty_queue`, `get_queue_size`
- `print_queue`

### Deque
Doubly-linked list based deque (int data).

| Type | Header |
|------|--------|
| `Deque` | `deque/deque.h` |

- `create_deque`, `free_deque`, `clear_deque`
- `push_front`, `pop_front`, `push_rear`, `pop_rear`
- `front`, `rear`
- `is_empty_deque`, `get_deque_size`
- `print_deque`, `print_deque_reverse`

### Hash Table
String-key → int-value hash table with chaining.

| Type | Header |
|------|--------|
| `HashTable` | `hashtable/hash_table.h` |

- `create_hash_table`, `free_hash_table`
- `hash_table_insert`, `hash_table_get`, `hash_table_delete`

### Tools

| Header | Functions |
|--------|-----------|
| `tools/max_min.h` | `max` / `min` — works on elements or arrays of `int`/`float`/`double` |
| `tools/pointer_transform.h` | Type conversion between `int*`/`float*`/`double*`/`Complex*` arrays |

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
| `string_lib` | String library |
| `stack_lib` | Stack |
| `queue_lib` | Queue |
| `deque_lib` | Deque |
| `hash_table_lib` | Hash table |
| `test_program_complex` | Complex number example |
| `test_program_vector` | Vector example |
| `test_program_matrix` | Matrix example |
| `test_program_string` | String example |
| `test_program_stack` | Stack example |
| `test_program_queue` | Queue example |
| `test_program_deque` | Deque example |
| `test_program_hash_table` | Hash table example |

## Project Structure

```
├── CMakeLists.txt
├── README.md
├── README_CN.md
├── include/
│   ├── complex/       # Complex number API
│   ├── vector/        # Vector API
│   ├── matrix/        # Matrix API (includes all sub-headers)
│   ├── string/        # String API
│   ├── stack/         # Stack API
│   ├── queue/         # Queue API
│   ├── deque/         # Deque API
│   ├── hashtable/     # Hash table API
│   └── tools/         # Utility functions
├── src/
│   ├── complex/       # Complex number implementation
│   ├── vector/        # Vector implementation
│   ├── matrix/        # Matrix implementation
│   ├── string/        # String implementation
│   ├── stack/         # Stack implementation
│   ├── queue/         # Queue implementation
│   ├── deque/         # Deque implementation
│   ├── hashtable/     # Hash table implementation
│   └── tools/         # Utility implementation
└── example/
    ├── complex_example.c
    ├── vector_example.c
    ├── matrix_example.c
    ├── string_example.c
    ├── stack_example.c
    ├── queue_example.c
    ├── deque_example.c
    └── hash_table_example.c
```

## Requirements

- C11 compiler (for `_Generic` support)
- CMake 3.10+
- Standard C library only (no external dependencies)
