add_library(solution "")

target_sources(
    solution
    PRIVATE
        solution.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/solution.hpp
    )

message(STATUS "the cmake current list dir is ${CMAKE_CURRENT_LIST_DIR}")

target_include_directories(
    solution
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
