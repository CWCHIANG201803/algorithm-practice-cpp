add_library(binaryTreeUtility "")
target_sources(
    binaryTreeUtility
    PRIVATE
        binaryTreeUtility.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/binaryTreeUtility.hpp
        ${PROJECT_SOURCE_DIR}/src/resources/TreeNode.hpp		    
    )

target_include_directories(
    binaryTreeUtility
		PUBLIC
		    ${PROJECT_SOURCE_DIR}/src/resources
)


target_include_directories(
    binaryTreeUtility
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )

