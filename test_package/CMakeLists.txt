PROJECT(PackageTest)
cmake_minimum_required(VERSION 3.0)

find_package(Porter2 REQUIRED)
ADD_EXECUTABLE(example example.cpp)
TARGET_LINK_LIBRARIES(example Porter2::Porter2)
