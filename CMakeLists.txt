cmake_minimum_required(VERSION 3.10)

project(example_complex)

# 设置 C 标准为 C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)  # 关闭 GNU 扩展，使用标准 C11

# 设置编译类型为 Debug（包含调试信息）
set(CMAKE_BUILD_TYPE Debug)

# 设置编译选项
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

include_directories(include)


# 库的源文件（不含main）
set(LIB_SOURCES_COMPLEX
    src/complex/operator_complex.c
    src/complex/print_complex.c
    src/complex/copy_complex.c
    src/complex/create_complex.c
    src/complex/free_complex.c
)

set(LIB_SOURCES_VECTOR
    src/vector/add_vector.c
    src/vector/create_vector.c
    src/vector/mul_vector.c
    src/vector/sub_vector.c
    src/vector/norm_vector.c
    src/vector/print_vector.c
    src/complex/operator_complex.c
    src/vector/replace_vector.c
    src/vector/remove_vector.c
    src/vector/free_vector.c
    src/vector/find_vector.c
    src/vector/copy_vector.c
    src/complex/print_complex.c
)

# 创建库
add_library(complex_lib ${LIB_SOURCES_COMPLEX})

target_include_directories(complex_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(vector_lib ${LIB_SOURCES_VECTOR})

target_include_directories(vector_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 创建测试可执行文件
add_executable(test_program_complex example/complex_example.c)
target_link_libraries(test_program_complex complex_lib)

add_executable(test_program_vector example/vector_example.c)
target_link_libraries(test_program_vector vector_lib)
