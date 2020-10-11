add_library(solution "")

target_sources(
    solution
    PRIVATE
        solution.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/solution.hpp
    )

target_include_directories(
    solution
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )

