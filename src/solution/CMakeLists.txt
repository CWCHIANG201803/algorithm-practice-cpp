add_library(MinStack "")

target_sources(
    MinStack
    PRIVATE
        MinStack.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/MinStack.hpp
    )

message(STATUS "the cmake current list dir is ${CMAKE_CURRENT_LIST_DIR}")

target_include_directories(
    MinStack
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
