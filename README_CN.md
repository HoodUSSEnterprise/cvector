# CVector — C 向量/矩阵/复数/字符串/数据结构 运算库

一个 C11 库，提供**复数**、**向量**（定长 2D/3D 与动态数组）、**矩阵**（全套线性代数）、**字符串**、**栈**、**队列**、**双端队列**和**哈希表**。利用 `_Generic` 实现类型泛型 API——同一函数名支持 `int`、`float`、`double` 和 `Complex`。

## 模块

### 复数 (`Complex`)
实部/虚部表示，支持完整算术运算。

| 类型 | 头文件 |
|------|--------|
| `Complex` | `complex/complex.h` |

- **算术运算**：`add_complex`、`sub_complex`、`mul_complex`、`div_complex`、`power_complex`
- **比较**：`is_equal_complex`
- **创建/释放**：`create_complex`、`copy_complex`、`free_complex`
- **打印**：`print_complex`

### 向量（定长 2D/3D 与动态数组）

| 类型 | 说明 | 头文件 |
|------|------|--------|
| `Vector2i/f/d/c` | 2 分量向量 | `vector/vector.h` |
| `Vector3i/f/d/c` | 3 分量向量 | `vector/vector.h` |
| `Vectori/f/d/c` | 动态数组 | `vector/vector.h` |

**定长向量运算**：`add_vec`、`sub_vec`、`mul_vec`、`norm_vec`（Lp 范数）、`print_vec`
**动态数组运算**：
- `create_vec`、`free_vec`、`print_vec`
- `push_back_vec`、`pop_vec`、`insert_vec`
- `remove_elem`、`remove_arr`、`replace_elem`、`replace_arr`
- `find_vec`、`reverse_vec`
- `copy_vec`

### 矩阵 (`MatrixI`、`MatrixF`、`MatrixD`、`MatrixC`)
全套线性代数，类型泛型宏支持。

| 类型 | 头文件 |
|------|--------|
| `MatrixI` (int)、`MatrixF` (float)、`MatrixD` (double)、`MatrixC` (Complex) | `matrix/matrix.h` |

**创建**：从数组（`int*`/`float*`/`double*`/`Complex*`）创建，自动类型转换；`identity_matrix`、`zero_matrix`、`eye_matrix`、`diag_matrix`、`random_matrix`、`random_col_vector`、`random_row_vector`
**算术运算**：`add_matrix`、`sub_matrix`、`mul_matrix`、`scalar_mul_matrix`、`pow_matrix`（支持负指数 = 逆矩阵的幂）
**线性代数**：`transpose_matrix`、`det_matrix`、`inv_matrix`、`rank_matrix`、`trace_matrix`、`minor_matrix`、`cofactor_matrix`、`adjugate_matrix`
**矩阵分解**：
- LU：`doolittle_matrixd`、`crout_matrixd`、`cholesky_matrixd`、`ldu_matrixd`、`can_lu_decomposition`
- QR：`qr_gs_matrixd/c`、`qr_householder_matrixd/c`、`gram_schmidt_matrixd/c`
- 特征值/特征向量：`eigenvalue_matrixd/c`、`eigenvector_matrixd`
**操作**：`copy_matrix`、`cat_matrix`（沿轴拼接）、`remove_matrix`（删除行列）、`replace_matrix`
**提取**：`col_vector_matrix`、`get_diag_matrix`
**搜索**：`find_matrix`（返回 `Pos` 坐标）
**性质检查**：`is_identity_matrix`、`is_inv_matrix`、`is_orth_matrix`、`is_positive_matrix`
**比较**：`is_equal_matrix`（支持跨类型）
**打印**：`print_matrix`

### 字符串 (`MyString`)
动态字符串，支持常见操作。

| 类型 | 头文件 |
|------|--------|
| `MyString` | `string/mystring.h` |

- **创建/释放**：`create_string`（从 `char*` 或 `MyString*`）、`free_string`
- **操作**：`append`（`char*` 或 `MyString*`）、`size`、`string_len`、`empty`
- **比较**：`equals`（`char*` 或 `MyString*`）、`compare`
- **查找**：`index_of`、`last_index_of`
- **类型转换**：`stoi`、`stof`、`stod`、`to_string`（`int`/`float`/`double`）
- **打印**：`print_string`

### 栈
基于链表的栈（int 数据）。

| 类型 | 头文件 |
|------|--------|
| `Stack` | `stack/stack.h` |

- `create_stack`、`free_stack`、`clear_stack`
- `push`、`pop`、`top`
- `is_empty_stack`、`get_stack_size`
- `print_stack`

### 队列
基于链表的队列（int 数据）。

| 类型 | 头文件 |
|------|--------|
| `Queue` | `queue/queue.h` |

- `create_queue`、`free_queue`、`clear_queue`
- `enqueue`、`dequeue`、`front`
- `is_empty_queue`、`get_queue_size`
- `print_queue`

### 双端队列
基于双向链表的双端队列（int 数据）。

| 类型 | 头文件 |
|------|--------|
| `Deque` | `deque/deque.h` |

- `create_deque`、`free_deque`、`clear_deque`
- `push_front`、`pop_front`、`push_rear`、`pop_rear`
- `front`、`rear`
- `is_empty_deque`、`get_deque_size`
- `print_deque`、`print_deque_reverse`

### 哈希表
字符串键 → 整型值的哈希表（链地址法）。

| 类型 | 头文件 |
|------|--------|
| `HashTable` | `hashtable/hash_table.h` |

- `create_hash_table`、`free_hash_table`
- `hash_table_insert`、`hash_table_get`、`hash_table_delete`

### 工具

| 头文件 | 函数 |
|--------|------|
| `tools/max_min.h` | `max` / `min` — 支持 `int`/`float`/`double` 的元素或数组 |
| `tools/pointer_transform.h` | `int*`/`float*`/`double*`/`Complex*` 数组间的类型转换 |

### Set（集合）
基于红黑树的整数集合。

| 类型 | 头文件 |
|------|--------|
| `Set` | `set/set.h` |

- `create_set`、`free_set`、`set_insert`、`set_delete`
- `set_contains`、`set_size`、`set_is_empty`
- `set_min`、`set_max`、`set_print`

### Map（映射）
基于红黑树的整数键 → 整数映射。

| 类型 | 头文件 |
|------|--------|
| `Map` | `map/map.h` |

- `create_map`、`free_map`、`map_put`、`map_delete`
- `map_get`（返回指针，不存在返回 NULL）、`map_contains`
- `map_size`、`map_is_empty`、`map_print`

## 快速开始

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

    // A * A^(-1) 应得到单位矩阵
    MatrixD *check = mul_matrix(m, inv);
    print_matrix(check);

    free_matrix(m);
    free_matrix(inv);
    free_matrix(check);
    return 0;
}
```

## 构建

### 使用 CMake
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### 构建目标
| 目标 | 说明 |
|--------|------|
| `complex_lib` | 复数库 |
| `vector_lib` | 向量库（依赖 complex_lib） |
| `matrix_lib` | 矩阵库（依赖 complex_lib） |
| `string_lib` | 字符串库 |
| `stack_lib` | 栈 |
| `queue_lib` | 队列 |
| `deque_lib` | 双端队列 |
| `hash_table_lib` | 哈希表 |
| `test_program_complex` | 复数示例程序 |
| `test_program_vector` | 向量示例程序 |
| `test_program_matrix` | 矩阵示例程序 |
| `test_program_string` | 字符串示例程序 |
| `test_program_stack` | 栈示例程序 |
| `test_program_queue` | 队列示例程序 |
| `test_program_deque` | 双端队列示例程序 |
| `test_program_hash_table` | 哈希表示例程序 |
| `test_program_set` | 集合示例程序 |
| `test_program_map` | 映射示例程序 |

## 项目结构

```
├── CMakeLists.txt
├── README.md
├── README_CN.md
├── include/
│   ├── complex/       # 复数 API
│   ├── vector/        # 向量 API
│   ├── matrix/        # 矩阵 API（包含所有子头文件）
│   ├── string/        # 字符串 API
│   ├── stack/         # 栈 API
│   ├── queue/         # 队列 API
│   ├── deque/         # 双端队列 API
│   ├── hashtable/     # 哈希表 API
│   ├── set/           # 集合 API
│   ├── map/           # 映射 API
│   └── tools/         # 工具函数
├── src/
│   ├── complex/       # 复数实现
│   ├── vector/        # 向量实现
│   ├── matrix/        # 矩阵实现
│   ├── string/        # 字符串实现
│   ├── stack/         # 栈实现
│   ├── queue/         # 队列实现
│   ├── deque/         # 双端队列实现
│   ├── hashtable/     # 哈希表实现
│   ├── set/           # 集合实现
│   ├── map/           # 映射实现
│   └── tools/         # 工具实现
└── example/
    ├── complex_example.c
    ├── vector_example.c
    ├── matrix_example.c
    ├── string_example.c
    ├── stack_example.c
    ├── queue_example.c
    ├── deque_example.c
    ├── hash_table_example.c
    ├── set_example.c
    └── map_example.c
```

## 环境要求

- C11 编译器（需要 `_Generic` 支持）
- CMake 3.10+
- 仅标准 C 库（无外部依赖）
