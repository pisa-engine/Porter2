cmake_minimum_required(VERSION 3.0)
project(Porter2 VERSION 1.0 LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()
MESSAGE( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE} )
include(cmake/verify_version.cmake)

#
# CONFIGURATION
#
set(Porter2_TARGET_NAME ${PROJECT_NAME})
set(Porter2_CONFIG_INSTALL_DIR "lib/cmake/${PROJECT_NAME}" CACHE INTERNAL "")
set(Porter2_INCLUDE_BUILD_DIR "${PROJECT_SOURCE_DIR}/include")
set(Porter2_INCLUDE_INSTALL_DIR "include")
set(Porter2_TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(Porter2_CMAKE_CONFIG_TEMPLATE "cmake/config.cmake.in")
set(Porter2_CMAKE_CONFIG_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(Porter2_CMAKE_VERSION_CONFIG_FILE
    "${Porter2_CMAKE_CONFIG_DIR}/${PROJECT_NAME}ConfigVersion.cmake")
set(Porter2_CMAKE_PROJECT_CONFIG_FILE
    "${Porter2_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Config.cmake")
set(Porter2_CMAKE_PROJECT_TARGETS_FILE
    "${Porter2_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Targets.cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# OPTIONS
#
option(Porter2_ENABLE_TESTING "Enable testing of the library." ON)

#
# DEPENDENCIES
#
add_subdirectory(external)

#
# ADD LIBRARY
#
add_library(${Porter2_TARGET_NAME}
    "${PROJECT_SOURCE_DIR}/src/Porter2.cpp")
target_include_directories(${Porter2_TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${Porter2_INCLUDE_BUILD_DIR}>
    $<INSTALL_INTERFACE:${Porter2_INCLUDE_INSTALL_DIR}>
)

include(CTest)
if (Porter2_ENABLE_TESTING AND BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

#
# INSTALL install header files, generate and install cmake config files for
# find_package()
#
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${Porter2_CMAKE_VERSION_CONFIG_FILE}
                                 COMPATIBILITY SameMajorVersion)
configure_file(${Porter2_CMAKE_CONFIG_TEMPLATE} ${Porter2_CMAKE_PROJECT_CONFIG_FILE}
               @ONLY)

install(FILES "${Porter2_INCLUDE_BUILD_DIR}/${PROJECT_NAME}.hpp"
        DESTINATION ${Porter2_INCLUDE_INSTALL_DIR})
install(FILES
        ${Porter2_CMAKE_PROJECT_CONFIG_FILE}
        ${Porter2_CMAKE_VERSION_CONFIG_FILE}
        DESTINATION ${Porter2_CONFIG_INSTALL_DIR})
export(TARGETS ${Porter2_TARGET_NAME}
       NAMESPACE ${PROJECT_NAME}::
       FILE ${Porter2_CMAKE_PROJECT_TARGETS_FILE})
install(TARGETS ${Porter2_TARGET_NAME}
        EXPORT ${Porter2_TARGETS_EXPORT_NAME}
        INCLUDES
        DESTINATION ${Porter2_INCLUDE_INSTALL_DIR}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        COMPONENT library)
install(EXPORT ${Porter2_TARGETS_EXPORT_NAME}
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${Porter2_CONFIG_INSTALL_DIR})
