cmake_minimum_required(VERSION 3.20.0)
project(data_structure)

include_directories(${CMAKE_SOURCE_DIR}/include)


aux_source_directory(${CMAKE_SOURCE_DIR} SRC_LIST)

add_executable(demo ${SRC_LIST})
