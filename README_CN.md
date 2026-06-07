# CVector — C 向量/矩阵/复数运算库

一个 C11 库，提供**向量**、**矩阵**和**复数**类型及全套线性代数运算。利用 `_Generic` 实现类型泛型 API——同一函数名支持 `int`、`float`、`double` 和 `Complex`。

## 功能特性

### 复数 (`Complex`)

- 算术运算：`add`、`sub`、`mul`、`div`、`power`
- 比较：`is_equal`
- 格式化打印

### 向量（定长 2D 向量和动态数组）

- **定长向量**：`Vector2i`、`Vector2f`、`Vector2d`、`Vector2c`（2 分量）
- **动态向量**：`Vectori`、`Vectorf`、`Vectord`、`Vectorc`（任意长度）
- 运算：`add`、`sub`、`mul`、`norm`（Lp 范数）、`print`
- 元素操作：`push_back`、`pop`、`insert`、`remove`（按值或数组）、`replace`、`find`、`reverse`

### 矩阵 (`MatrixI`、`MatrixF`、`MatrixD`、`MatrixC`)

- **创建**：从数组（`int*`、`float*`、`double*`、`Complex*`）创建，自动类型转换
- **特殊矩阵**：`identity`（单位矩阵）、`zero`（零矩阵）、`eye`、`diag`（对角矩阵）
- **随机矩阵**：`random_matrix`、`random_col_vector`、`random_row_vector`
- **算术运算**：`add`、`sub`、`mul`、`scalar_mul`、`pow`（支持负指数 = 逆矩阵的幂）
- **线性代数**：
  - 转置、行列式、逆矩阵
  - 秩、迹
  - 余子式、代数余子式、伴随矩阵
  - LU 分解（Doolittle、Crout、Cholesky、LDU）
  - QR 分解（Gram-Schmidt、Householder）
  - 特征值（QR 迭代法）和特征向量
- **操作**：`copy`（复制）、`cat`（拼接）、`remove`（删除行列）、`replace`（替换元素）
- **提取**：列向量、对角线元素
- **搜索**：`find` 元素（返回位置）
- **性质检查**：`is_identity`（是否单位矩阵）、`is_inv`（是否可逆）、`is_orth`（是否正交）、`is_positive`（是否正定）、`can_lu_decomposition`（能否 LU 分解）
- **比较**：`is_equal` 支持跨类型比较
- **打印**：格式化矩阵输出

### 类型泛型宏

所有主要操作均使用 C11 `_Generic`——无论元素类型是什么，统一调用 `add_matrix(m1, m2)`。

| 宏                                       | 自动检测         |
| ---------------------------------------- | ---------------- |
| `create_matrixi/f/d/c`                   | 输入数据指针类型 |
| `add_matrix`、`sub_matrix`、`mul_matrix` | 两个操作数类型   |
| `scalar_mul_matrix`                      | 矩阵和标量类型   |
| `cat_matrix`                             | 两个操作数类型   |
| `det_matrix`、`inv_matrix`、`pow_matrix` | 输入类型         |
| `transpose_matrix`、`copy_matrix`        | 输入类型         |
| `print_matrix`、`free_matrix`            | 输入类型         |
| `is_equal_matrix`                        | 两个操作数类型   |
| `find_matrix`、`replace_matrix`          | 输入类型         |
| `remove_matrix`                          | 输入类型         |

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
    printf("trace(A) = %lf\n", trace_matrix(m));

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

| 目标                   | 说明                       |
| ---------------------- | -------------------------- |
| `complex_lib`          | 复数库                     |
| `vector_lib`           | 向量库（依赖 complex_lib） |
| `matrix_lib`           | 矩阵库（依赖 complex_lib） |
| `string_lib`           | 字符串库                   |
| `test_program_complex` | 复数示例程序               |
| `test_program_vector`  | 向量示例程序               |
| `test_program_matrix`  | 矩阵示例程序               |
| `test_program_string`  | 示例程序                   |

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
│   └── tools/         # 工具函数
├── src/
│   ├── complex/       # 复数实现
│   ├── vector/        # 向量实现
│   ├── matrix/        # 矩阵实现
│   ├── string/        # 字符串实现
│   └── tools/         # 工具实现
└── example/
    ├── complex_example.c
    ├── vector_example.c
    └── matrix_example.c
    └── string_example.c
```

## 环境要求

- C11 编译器（需要 `_Generic` 支持）
- CMake 3.10+
- 仅标准 C 库（无外部依赖）
