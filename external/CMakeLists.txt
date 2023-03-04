EXECUTE_PROCESS(COMMAND git submodule update --init
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..
                OUTPUT_QUIET
        )

if (Porter2_ENABLE_TESTING AND BUILD_TESTING)
    add_subdirectory(googletest EXCLUDE_FROM_ALL)
endif()
