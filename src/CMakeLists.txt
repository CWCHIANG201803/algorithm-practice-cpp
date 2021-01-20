add_subdirectory(solution)
add_subdirectory(utility)

add_executable(main main.cpp)

target_link_libraries(main solution utility)