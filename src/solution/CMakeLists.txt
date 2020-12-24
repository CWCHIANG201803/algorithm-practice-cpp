add_library(Solution "")

target_sources(
    Solution
    PRIVATE
        Solution.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Solution.hpp
    )

message(STATUS "the cmake current list dir is ${CMAKE_CURRENT_LIST_DIR}")

target_include_directories(
    Solution
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
