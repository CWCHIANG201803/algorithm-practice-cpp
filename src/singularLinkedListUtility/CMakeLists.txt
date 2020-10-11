add_library(singularLinkedListUtility "")


target_sources(
    singularLinkedListUtility
    PRIVATE
        singularLinkedListUtility.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/singularLinkedListUtility.hpp 
				${PROJECT_SOURCE_DIR}/src/resources/ListNode.hpp
    )

target_include_directories(
    singularLinkedListUtility
		PUBLIC
		    ${PROJECT_SOURCE_DIR}/src/resources
)

target_include_directories(
    singularLinkedListUtility
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR} 
    )  
