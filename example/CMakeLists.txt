cmake_minimum_required(VERSION 3.10)

project(example_complex)

# 设置 C 标准为 C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)  # 关闭 GNU 扩展，使用标准 C11

set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")

# 设置编译类型为 Debug（包含调试信息）
set(CMAKE_BUILD_TYPE Debug)

# 设置编译选项
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

include_directories(${PROJECT_ROOT}/include)

# 库的源文件（不含main）
set(LIB_SOURCES_COMPLEX
    ${PROJECT_ROOT}/src/complex/operator_complex.c
    ${PROJECT_ROOT}/src/complex/print_complex.c
    ${PROJECT_ROOT}/src/complex/copy_complex.c
    ${PROJECT_ROOT}/src/complex/create_complex.c
    ${PROJECT_ROOT}/src/complex/free_complex.c
)

set(LIB_SOURCES_VECTOR
    ${PROJECT_ROOT}/src/vector/add_vector.c
    ${PROJECT_ROOT}/src/vector/create_vector.c
    ${PROJECT_ROOT}/src/vector/mul_vector.c
    ${PROJECT_ROOT}/src/vector/sub_vector.c
    ${PROJECT_ROOT}/src/vector/norm_vector.c
    ${PROJECT_ROOT}/src/vector/print_vector.c
    ${PROJECT_ROOT}/src/complex/operator_complex.c
    ${PROJECT_ROOT}/src/vector/replace_vector.c
    ${PROJECT_ROOT}/src/vector/remove_vector.c
    ${PROJECT_ROOT}/src/vector/free_vector.c
    ${PROJECT_ROOT}/src/vector/find_vector.c
    ${PROJECT_ROOT}/src/vector/copy_vector.c
    ${PROJECT_ROOT}/src/complex/print_complex.c
)

# 创建库
add_library(complex_lib ${LIB_SOURCES_COMPLEX})

target_include_directories(complex_lib PUBLIC ${PROJECT_ROOT}/include)

add_library(vector_lib ${LIB_SOURCES_VECTOR})

target_include_directories(vector_lib PUBLIC ${PROJECT_ROOT}/include)

# 创建测试可执行文件
add_executable(test_program_complex ${PROJECT_ROOT}/example/complex_example.c)
target_link_libraries(test_program_complex complex_lib)

add_executable(test_program_vector ${PROJECT_ROOT}/example/vector_example.c)
target_link_libraries(test_program_vector vector_lib)

set(LIB_SOURCES_MATRIX
    ${PROJECT_ROOT}/src/matrix/add_matrix.c
    ${PROJECT_ROOT}/src/matrix/adjugate_matrix.c
    ${PROJECT_ROOT}/src/matrix/cat_matrix.c
    ${PROJECT_ROOT}/src/matrix/check_matrix.c
    ${PROJECT_ROOT}/src/matrix/cofactor_matrix.c
    ${PROJECT_ROOT}/src/matrix/compare_matrix.c
    ${PROJECT_ROOT}/src/matrix/copy_matrix.c
    ${PROJECT_ROOT}/src/matrix/create_matrix.c
    ${PROJECT_ROOT}/src/matrix/determinant_matrix.c
    ${PROJECT_ROOT}/src/matrix/eigen_matrix.c
    ${PROJECT_ROOT}/src/matrix/extract_matrix.c
    ${PROJECT_ROOT}/src/matrix/find_matrix.c
    ${PROJECT_ROOT}/src/matrix/free_matrix.c
    ${PROJECT_ROOT}/src/matrix/inv_matrix.c
    ${PROJECT_ROOT}/src/matrix/lu_matrix.c
    ${PROJECT_ROOT}/src/matrix/mul_matrix.c
    ${PROJECT_ROOT}/src/matrix/pow_matrix.c
    ${PROJECT_ROOT}/src/matrix/print_matrix.c
    ${PROJECT_ROOT}/src/matrix/qr_matrix.c
    ${PROJECT_ROOT}/src/matrix/random_tool.c
    ${PROJECT_ROOT}/src/matrix/rank_trace_matrix.c
    ${PROJECT_ROOT}/src/matrix/remove_line_matrix.c
    ${PROJECT_ROOT}/src/matrix/replace_matrix.c
    ${PROJECT_ROOT}/src/matrix/scalar_mul_matrix.c
    ${PROJECT_ROOT}/src/matrix/special_matrix.c
    ${PROJECT_ROOT}/src/matrix/sub_matrix.c
    ${PROJECT_ROOT}/src/matrix/transpose_matrix.c
    ${PROJECT_ROOT}/src/tools/max_min.c
    ${PROJECT_ROOT}/src/tools/pointer_transform.c
)

add_library(matrix_lib ${LIB_SOURCES_MATRIX})

target_include_directories(matrix_lib PUBLIC ${PROJECT_ROOT}/include)
target_link_libraries(matrix_lib complex_lib)

add_executable(test_program_matrix ${PROJECT_ROOT}/example/matrix_example.c)
target_link_libraries(test_program_matrix matrix_lib)

set(LIB_SOURCES_STRING
    ${PROJECT_ROOT}/src/string/create_string.c
    ${PROJECT_ROOT}/src/string/find_string.c
    ${PROJECT_ROOT}/src/string/free_string.c
    ${PROJECT_ROOT}/src/string/print_string.c
    ${PROJECT_ROOT}/src/string/number_string.c
    ${PROJECT_ROOT}/src/string/operator_string.c
)

add_library(string_lib ${LIB_SOURCES_STRING})

target_include_directories(string_lib PUBLIC ${PROJECT_ROOT}/include)
# target_link_libraries(matrix_lib complex_lib)

add_executable(test_program_string ${PROJECT_ROOT}/example/string_example.c)
target_link_libraries(test_program_string string_lib)

set(LIB_SOURCES_HASHTABLE
    ${PROJECT_ROOT}/src/hashtable/create_hash_table.c
    ${PROJECT_ROOT}/src/hashtable/delete_node.c
    ${PROJECT_ROOT}/src/hashtable/free_hash_table.c
    ${PROJECT_ROOT}/src/hashtable/get_hash_table.c
    ${PROJECT_ROOT}/src/hashtable/insert_hash_table.c
)

add_library(hash_table_lib ${LIB_SOURCES_HASHTABLE})

target_include_directories(hash_table_lib PUBLIC ${PROJECT_ROOT}/include)
# target_link_libraries(matrix_lib complex_lib)

add_executable(test_program_hash_table ${PROJECT_ROOT}/example/hash_table_example.c)
target_link_libraries(test_program_hash_table hash_table_lib)

set(LIB_SOURCES_STACK
    ${PROJECT_ROOT}/src/stack/clear_stack.c
    ${PROJECT_ROOT}/src/stack/create_stack.c
    ${PROJECT_ROOT}/src/stack/free_stack.c
    ${PROJECT_ROOT}/src/stack/pop_stack.c
    ${PROJECT_ROOT}/src/stack/push_stack.c
    ${PROJECT_ROOT}/src/stack/print_stack.c
    ${PROJECT_ROOT}/src/stack/operator_stack.c
)

add_library(stack_lib ${LIB_SOURCES_STACK})

target_include_directories(stack_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_stack ${PROJECT_ROOT}/example/stack_example.c)
target_link_libraries(test_program_stack stack_lib)

set(LIB_SOURCES_QUEUE
    ${PROJECT_ROOT}/src/queue/clear_queue.c
    ${PROJECT_ROOT}/src/queue/create_queue.c
    ${PROJECT_ROOT}/src/queue/de_queue.c
    ${PROJECT_ROOT}/src/queue/empty_queue.c
    ${PROJECT_ROOT}/src/queue/en_queue.c
    ${PROJECT_ROOT}/src/queue/free_queue.c
    ${PROJECT_ROOT}/src/queue/front_queue.c
    ${PROJECT_ROOT}/src/queue/print_queue.c
    ${PROJECT_ROOT}/src/queue/size_queue.c
)

add_library(queue_lib ${LIB_SOURCES_QUEUE})

target_include_directories(queue_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_queue ${PROJECT_ROOT}/example/queue_example.c)
target_link_libraries(test_program_queue queue_lib)

set(LIB_SOURCES_DEQUE
    ${PROJECT_ROOT}/src/deque/clear_deque.c
    ${PROJECT_ROOT}/src/deque/create_deque.c
    ${PROJECT_ROOT}/src/deque/empty_deque.c
    ${PROJECT_ROOT}/src/deque/free_deque.c
    ${PROJECT_ROOT}/src/deque/front_deque.c
    ${PROJECT_ROOT}/src/deque/pop_front_deque.c
    ${PROJECT_ROOT}/src/deque/pop_rear_deque.c
    ${PROJECT_ROOT}/src/deque/print_deque_reverse.c
    ${PROJECT_ROOT}/src/deque/print_deque.c
    ${PROJECT_ROOT}/src/deque/push_front_deque.c
    ${PROJECT_ROOT}/src/deque/push_rear_deque.c
    ${PROJECT_ROOT}/src/deque/rear_deque.c
    ${PROJECT_ROOT}/src/deque/size_deque.c
)

add_library(deque_lib ${LIB_SOURCES_DEQUE})

target_include_directories(deque_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_deque ${PROJECT_ROOT}/example/deque_example.c)
target_link_libraries(test_program_deque deque_lib)

set(LIB_SOURCES_RBTREE
    ${PROJECT_ROOT}/src/rbtree/create_rbtree.c
    ${PROJECT_ROOT}/src/rbtree/insert_rbtree.c
    ${PROJECT_ROOT}/src/rbtree/delete_rbtree.c
    ${PROJECT_ROOT}/src/rbtree/find_rbtree.c
    ${PROJECT_ROOT}/src/rbtree/free_rbtree.c
    ${PROJECT_ROOT}/src/rbtree/print_rbtree.c
    ${PROJECT_ROOT}/src/rbtree/operator_rbtree.c
    ${PROJECT_ROOT}/src/rbtree/count_rbtree.c
)

add_library(rbtree_lib ${LIB_SOURCES_RBTREE})

target_include_directories(rbtree_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_rbtree ${PROJECT_ROOT}/example/rbtree_example.c)
target_link_libraries(test_program_rbtree rbtree_lib)

set(LIB_SOURCES_SET
    ${PROJECT_ROOT}/src/set/create_set.c
    ${PROJECT_ROOT}/src/set/insert_set.c
    ${PROJECT_ROOT}/src/set/delete_set.c
    ${PROJECT_ROOT}/src/set/find_set.c
    ${PROJECT_ROOT}/src/set/free_set.c
    ${PROJECT_ROOT}/src/set/operator_set.c
)

add_library(set_lib ${LIB_SOURCES_SET})

target_include_directories(set_lib PUBLIC ${PROJECT_ROOT}/include)
target_link_libraries(set_lib rbtree_lib)

add_executable(test_program_set ${PROJECT_ROOT}/example/set_example.c)
target_link_libraries(test_program_set set_lib)

set(LIB_SOURCES_MAP
    ${PROJECT_ROOT}/src/map/create_map.c
    ${PROJECT_ROOT}/src/map/insert_map.c
    ${PROJECT_ROOT}/src/map/delete_map.c
    ${PROJECT_ROOT}/src/map/find_map.c
    ${PROJECT_ROOT}/src/map/free_map.c
    ${PROJECT_ROOT}/src/map/operator_map.c
)

add_library(map_lib ${LIB_SOURCES_MAP})

target_include_directories(map_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_map ${PROJECT_ROOT}/example/map_example.c)
target_link_libraries(test_program_map map_lib)

set(LIB_SOURCES_FORWARDLIST
    ${PROJECT_ROOT}/src/forwardlist/create_forwardlist.c
    ${PROJECT_ROOT}/src/forwardlist/push_front_forwardlist.c
    ${PROJECT_ROOT}/src/forwardlist/pop_front_forwardlist.c
    ${PROJECT_ROOT}/src/forwardlist/operator_forwardlist.c
    ${PROJECT_ROOT}/src/forwardlist/print_forwardlist.c
    ${PROJECT_ROOT}/src/forwardlist/free_forwardlist.c
)

add_library(forwardlist_lib ${LIB_SOURCES_FORWARDLIST})

target_include_directories(forwardlist_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_forwardlist ${PROJECT_ROOT}/example/forwardlist_example.c)
target_link_libraries(test_program_forwardlist forwardlist_lib)

set(LIB_SOURCES_PRIORITYQUEUE
    ${PROJECT_ROOT}/src/priorityqueue/create_priorityqueue.c
    ${PROJECT_ROOT}/src/priorityqueue/push_priorityqueue.c
    ${PROJECT_ROOT}/src/priorityqueue/pop_priorityqueue.c
    ${PROJECT_ROOT}/src/priorityqueue/operator_priorityqueue.c
    ${PROJECT_ROOT}/src/priorityqueue/print_priorityqueue.c
    ${PROJECT_ROOT}/src/priorityqueue/free_priorityqueue.c
)

add_library(priorityqueue_lib ${LIB_SOURCES_PRIORITYQUEUE})

target_include_directories(priorityqueue_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_priorityqueue ${PROJECT_ROOT}/example/priorityqueue_example.c)
target_link_libraries(test_program_priorityqueue priorityqueue_lib)

set(LIB_SOURCES_UNORDERED_MAP
    ${PROJECT_ROOT}/src/unordered_map/create_unordered_map.c
    ${PROJECT_ROOT}/src/unordered_map/insert_unordered_map.c
    ${PROJECT_ROOT}/src/unordered_map/delete_unordered_map.c
    ${PROJECT_ROOT}/src/unordered_map/find_unordered_map.c
    ${PROJECT_ROOT}/src/unordered_map/free_unordered_map.c
    ${PROJECT_ROOT}/src/unordered_map/operator_unordered_map.c
    ${PROJECT_ROOT}/src/unordered_map/print_unordered_map.c
)

add_library(unordered_map_lib ${LIB_SOURCES_UNORDERED_MAP})

target_include_directories(unordered_map_lib PUBLIC ${PROJECT_ROOT}/include)

set(LIB_SOURCES_UNORDERED_SET
    ${PROJECT_ROOT}/src/unordered_set/create_unordered_set.c
    ${PROJECT_ROOT}/src/unordered_set/insert_unordered_set.c
    ${PROJECT_ROOT}/src/unordered_set/delete_unordered_set.c
    ${PROJECT_ROOT}/src/unordered_set/find_unordered_set.c
    ${PROJECT_ROOT}/src/unordered_set/free_unordered_set.c
    ${PROJECT_ROOT}/src/unordered_set/operator_unordered_set.c
    ${PROJECT_ROOT}/src/unordered_set/print_unordered_set.c
)

add_library(unordered_set_lib ${LIB_SOURCES_UNORDERED_SET})

target_include_directories(unordered_set_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_unorder ${PROJECT_ROOT}/example/unorder_example.c)
target_link_libraries(test_program_unorder unordered_map_lib unordered_set_lib)

set(LIB_SOURCES_UNORDERED_MULTISET
    ${PROJECT_ROOT}/src/unordered_multiset/create_unordered_multiset.c
    ${PROJECT_ROOT}/src/unordered_multiset/insert_unordered_multiset.c
    ${PROJECT_ROOT}/src/unordered_multiset/delete_unordered_multiset.c
    ${PROJECT_ROOT}/src/unordered_multiset/find_unordered_multiset.c
    ${PROJECT_ROOT}/src/unordered_multiset/free_unordered_multiset.c
    ${PROJECT_ROOT}/src/unordered_multiset/operator_unordered_multiset.c
    ${PROJECT_ROOT}/src/unordered_multiset/print_unordered_multiset.c
)

add_library(unordered_multiset_lib ${LIB_SOURCES_UNORDERED_MULTISET})

target_include_directories(unordered_multiset_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_unordered_multiset ${PROJECT_ROOT}/example/unordered_multiset_example.c)
target_link_libraries(test_program_unordered_multiset unordered_multiset_lib)

set(LIB_SOURCES_UNORDERED_MULTIMAP
    ${PROJECT_ROOT}/src/unordered_multimap/create_unordered_multimap.c
    ${PROJECT_ROOT}/src/unordered_multimap/insert_unordered_multimap.c
    ${PROJECT_ROOT}/src/unordered_multimap/delete_unordered_multimap.c
    ${PROJECT_ROOT}/src/unordered_multimap/find_unordered_multimap.c
    ${PROJECT_ROOT}/src/unordered_multimap/free_unordered_multimap.c
    ${PROJECT_ROOT}/src/unordered_multimap/operator_unordered_multimap.c
    ${PROJECT_ROOT}/src/unordered_multimap/print_unordered_multimap.c
)

add_library(unordered_multimap_lib ${LIB_SOURCES_UNORDERED_MULTIMAP})

target_include_directories(unordered_multimap_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_unordered_multimap ${PROJECT_ROOT}/example/unordered_multimap_example.c)
target_link_libraries(test_program_unordered_multimap unordered_multimap_lib)

set(LIB_SOURCES_MULTISET
    ${PROJECT_ROOT}/src/multiset/create_multiset.c
    ${PROJECT_ROOT}/src/multiset/insert_multiset.c
    ${PROJECT_ROOT}/src/multiset/delete_multiset.c
    ${PROJECT_ROOT}/src/multiset/find_multiset.c
    ${PROJECT_ROOT}/src/multiset/free_multiset.c
    ${PROJECT_ROOT}/src/multiset/operator_multiset.c
    ${PROJECT_ROOT}/src/multiset/print_multiset.c
)

add_library(multiset_lib ${LIB_SOURCES_MULTISET})

target_include_directories(multiset_lib PUBLIC ${PROJECT_ROOT}/include)
target_link_libraries(multiset_lib rbtree_lib)

add_executable(test_program_multiset ${PROJECT_ROOT}/example/multiset_example.c)
target_link_libraries(test_program_multiset multiset_lib)

set(LIB_SOURCES_MULTIMAP
    ${PROJECT_ROOT}/src/multimap/create_multimap.c
    ${PROJECT_ROOT}/src/multimap/insert_multimap.c
    ${PROJECT_ROOT}/src/multimap/delete_multimap.c
    ${PROJECT_ROOT}/src/multimap/find_multimap.c
    ${PROJECT_ROOT}/src/multimap/free_multimap.c
    ${PROJECT_ROOT}/src/multimap/operator_multimap.c
    ${PROJECT_ROOT}/src/multimap/print_multimap.c
)

add_library(multimap_lib ${LIB_SOURCES_MULTIMAP})

target_include_directories(multimap_lib PUBLIC ${PROJECT_ROOT}/include)

add_executable(test_program_multimap ${PROJECT_ROOT}/example/multimap_example.c)
target_link_libraries(test_program_multimap multimap_lib)
