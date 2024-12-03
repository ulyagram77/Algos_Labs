cmake_minimum_required(VERSION 2.8)

project(main LANGUAGES C)

include_directories(
    libs/task_manager
    libs/general_utils
    libs/linked_list
    libs/lab8_list
)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(libs/task_manager)
add_subdirectory(libs/general_utils)
add_subdirectory(libs/linked_list)
add_subdirectory(libs/lab8_list)

add_subdirectory(tasks)

target_link_libraries(${PROJECT_NAME}
    PRIVATE task_manager
    PRIVATE tasks
    PRIVATE general_utils
    PRIVATE linked_list
    PRIVATE lab8_list
)