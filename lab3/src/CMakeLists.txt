cmake_minimum_required(VERSION 2.8)

project(main LANGUAGES C)

include_directories(
    libs/task_manager
    libs/general_utils
    tasks
)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(libs/task_manager)
add_subdirectory(libs/general_utils)

add_subdirectory(tasks)

target_link_libraries(${PROJECT_NAME}
    PRIVATE task_manager
    PRIVATE tasks
    PRIVATE general_utils
)