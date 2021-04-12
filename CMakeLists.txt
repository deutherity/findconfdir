cmake_minimum_required(VERSION 3.10)

project(findconfdir VERSION 1.0.0)

add_library(${PROJECT_NAME} findconfdir.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/headers)
target_compile_definitions(${PROJECT_NAME}
    PRIVATE PROJECTNAME="${CMAKE_PROJECT_NAME}"
)
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDART_REQUIRED TRUE
)
