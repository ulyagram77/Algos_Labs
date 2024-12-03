cmake_minimum_required(VERSION 2.8)

project(main LANGUAGES C)

include_directories(
    libs/task_manager
    libs/general_utils
    libs/sparse_table
    libs/string_vector
    libs/string_block-linked
    libs/linked_list
    libs/priority_queue_arr
    libs/priority_queue_list
    tasks
)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(libs/task_manager)
add_subdirectory(libs/general_utils)
add_subdirectory(libs/sparse_table)
add_subdirectory(libs/string_vector)
add_subdirectory(libs/string_block-linked)
add_subdirectory(libs/linked_list)
add_subdirectory(libs/priority_queue_arr)
add_subdirectory(libs/priority_queue_list)


add_subdirectory(tasks)

target_link_libraries(${PROJECT_NAME}
    PRIVATE task_manager
    PRIVATE tasks
    PRIVATE general_utils
    PRIVATE sparse_table
    PRIVATE string_vector
    PRIVATE string_block-linked
    PRIVATE linked_list
    PRIVATE priority_queue_arr
    PRIVATE priority_queue_list
)