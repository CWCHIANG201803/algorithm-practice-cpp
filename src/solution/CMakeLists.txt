add_library(WordDistance "")

target_sources(
    WordDistance
    PRIVATE
    WordDistance.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/WordDistance.hpp
    )

message(STATUS "the cmake current list dir is ${CMAKE_CURRENT_LIST_DIR}")

target_include_directories(
    WordDistance
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
