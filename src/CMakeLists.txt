add_subdirectory(solution)

add_executable(main main.cpp)

target_link_libraries(main LFUCache)