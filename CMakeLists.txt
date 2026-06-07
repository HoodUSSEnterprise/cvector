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

set(LIB_SOURCES_MATRIX
    src/matrix/add_matrix.c
    src/matrix/adjugate_matrix.c
    src/matrix/cat_matrix.c
    src/matrix/check_matrix.c
    src/matrix/cofactor_matrix.c
    src/matrix/compare_matrix.c
    src/matrix/copy_matrix.c
    src/matrix/create_matrix.c
    src/matrix/determinant_matrix.c
    src/matrix/eigen_matrix.c
    src/matrix/extract_matrix.c
    src/matrix/find_matrix.c
    src/matrix/free_matrix.c
    src/matrix/inv_matrix.c
    src/matrix/lu_matrix.c
    src/matrix/mul_matrix.c
    src/matrix/pow_matrix.c
    src/matrix/print_matrix.c
    src/matrix/qr_matrix.c
    src/matrix/random_tool.c
    src/matrix/rank_trace_matrix.c
    src/matrix/remove_line_matrix.c
    src/matrix/replace_matrix.c
    src/matrix/scalar_mul_matrix.c
    src/matrix/special_matrix.c
    src/matrix/sub_matrix.c
    src/matrix/transpose_matrix.c
    src/tools/max_min.c
    src/tools/pointer_transform.c
)

add_library(matrix_lib ${LIB_SOURCES_MATRIX})

target_include_directories(matrix_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(matrix_lib complex_lib)

add_executable(test_program_matrix example/matrix_example.c)
target_link_libraries(test_program_matrix matrix_lib)

set(LIB_SOURCES_STRING
    src/string/create_string.c
    src/string/find_string.c
    src/string/free_string.c
    src/string/print_string.c
    src/string/number_string.c
    src/string/operator_string.c
)

add_library(string_lib ${LIB_SOURCES_STRING})

target_include_directories(string_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
# target_link_libraries(matrix_lib complex_lib)

add_executable(test_program_string example/string_example.c)
target_link_libraries(test_program_string string_lib)

set(LIB_SOURCES_HASHTABLE
    src/hashtable/create_hash_table.c
    src/hashtable/delete_node.c
    src/hashtable/free_hash_table.c
    src/hashtable/get_hash_table.c
    src/hashtable/insert_hash_table.c
)

add_library(hash_table_lib ${LIB_SOURCES_HASHTABLE})

target_include_directories(hash_table_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
# target_link_libraries(matrix_lib complex_lib)

add_executable(test_program_hash_table example/hash_table_example.c)
target_link_libraries(test_program_hash_table hash_table_lib)

set(LIB_SOURCES_STACK
    src/stack/clear_stack.c
    src/stack/create_stack.c
    src/stack/free_stack.c
    src/stack/pop_stack.c
    src/stack/push_stack.c
    src/stack/print_stack.c
    src/stack/operator_stack.c
)

add_library(stack_lib ${LIB_SOURCES_STACK})

target_include_directories(stack_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_program_stack example/stack_example.c)
target_link_libraries(test_program_stack stack_lib)

set(LIB_SOURCES_QUEUE
    src/queue/clear_queue.c
    src/queue/create_queue.c
    src/queue/de_queue.c
    src/queue/empty_queue.c
    src/queue/en_queue.c
    src/queue/free_queue.c
    src/queue/front_queue.c
    src/queue/print_queue.c
    src/queue/size_queue.c
)

add_library(queue_lib ${LIB_SOURCES_QUEUE})

target_include_directories(queue_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_program_queue example/queue_example.c)
target_link_libraries(test_program_queue queue_lib)

set(LIB_SOURCES_DEQUE
    src/deque/clear_deque.c
    src/deque/create_deque.c
    src/deque/empty_deque.c
    src/deque/free_deque.c
    src/deque/front_deque.c
    src/deque/pop_front_deque.c
    src/deque/pop_rear_deque.c
    src/deque/print_deque_reverse.c
    src/deque/print_deque.c
    src/deque/push_front_deque.c
    src/deque/push_rear_deque.c
    src/deque/rear_deque.c
    src/deque/size_deque.c
)

add_library(deque_lib ${LIB_SOURCES_DEQUE})

target_include_directories(deque_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_program_deque example/deque_example.c)
target_link_libraries(test_program_deque deque_lib)

set(LIB_SOURCES_RBTREE
    src/rbtree/create_rbtree.c
    src/rbtree/insert_rbtree.c
    src/rbtree/delete_rbtree.c
    src/rbtree/find_rbtree.c
    src/rbtree/free_rbtree.c
    src/rbtree/print_rbtree.c
    src/rbtree/operator_rbtree.c
)

add_library(rbtree_lib ${LIB_SOURCES_RBTREE})

target_include_directories(rbtree_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_program_rbtree example/rbtree_example.c)
target_link_libraries(test_program_rbtree rbtree_lib)

set(LIB_SOURCES_SET
    src/set/create_set.c
    src/set/insert_set.c
    src/set/delete_set.c
    src/set/find_set.c
    src/set/free_set.c
    src/set/operator_set.c
)

add_library(set_lib ${LIB_SOURCES_SET})

target_include_directories(set_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(set_lib rbtree_lib)

add_executable(test_program_set example/set_example.c)
target_link_libraries(test_program_set set_lib)

set(LIB_SOURCES_MAP
    src/map/create_map.c
    src/map/insert_map.c
    src/map/delete_map.c
    src/map/find_map.c
    src/map/free_map.c
    src/map/operator_map.c
)

add_library(map_lib ${LIB_SOURCES_MAP})

target_include_directories(map_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_program_map example/map_example.c)
target_link_libraries(test_program_map map_lib)

set(LIB_SOURCES_FORWARDLIST
    src/forwardlist/create_forwardlist.c
    src/forwardlist/push_front_forwardlist.c
    src/forwardlist/pop_front_forwardlist.c
    src/forwardlist/operator_forwardlist.c
    src/forwardlist/print_forwardlist.c
    src/forwardlist/free_forwardlist.c
)

add_library(forwardlist_lib ${LIB_SOURCES_FORWARDLIST})

target_include_directories(forwardlist_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_program_forwardlist example/forwardlist_example.c)
target_link_libraries(test_program_forwardlist forwardlist_lib)
