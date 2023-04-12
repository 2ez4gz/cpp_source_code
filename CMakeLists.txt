cmake_minimum_required(VERSION 3.24)
project(cpp_source_code)

set(CMAKE_CXX_STANDARD 14)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach()
