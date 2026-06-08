cmake_minimum_required(VERSION 3.10)
project(stack_visualize)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")

include_directories(${PROJECT_ROOT}/include)

list(APPEND CMAKE_PREFIX_PATH ${PROJECT_ROOT}/lib)
set(SDL3_DIR "D:/C++lib/SDL3-3.4.8/cmake")
find_package(SDL3 REQUIRED)
set(SDL3_ttf_DIR "D:/C++lib/SDL3_ttf-3.2.2/cmake")
find_package(SDL3_ttf QUIET)

set(STACK_SOURCES
    ${PROJECT_ROOT}/src/stack/create_stack.c
    ${PROJECT_ROOT}/src/stack/push_stack.c
    ${PROJECT_ROOT}/src/stack/pop_stack.c
    ${PROJECT_ROOT}/src/stack/operator_stack.c
    ${PROJECT_ROOT}/src/stack/clear_stack.c
    ${PROJECT_ROOT}/src/stack/print_stack.c
    ${PROJECT_ROOT}/src/stack/free_stack.c
)

add_executable(stack_visualize main.c ${STACK_SOURCES})

target_link_libraries(stack_visualize PRIVATE SDL3::SDL3)

if(SDL3_ttf_FOUND)
    target_link_libraries(stack_visualize PRIVATE SDL3_ttf::SDL3_ttf)
    target_compile_definitions(stack_visualize PRIVATE USE_SDL_TTF)
    add_custom_command(TARGET stack_visualize POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_ROOT}/lib/SDL3_ttf.dll"
            "$<TARGET_FILE_DIR:stack_visualize>/"
    )
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(stack_visualize PRIVATE -static-libgcc)
endif()

add_custom_command(TARGET stack_visualize POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_ROOT}/lib/SDL3.dll"
        "$<TARGET_FILE_DIR:stack_visualize>/"
)
