add_library(LFUCache "")

target_sources(
    LFUCache
    PRIVATE
        LFUCache.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/LFUCache.hpp
    )

message(STATUS "the cmake current list dir is ${CMAKE_CURRENT_LIST_DIR}")

target_include_directories(
    LFUCache
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
