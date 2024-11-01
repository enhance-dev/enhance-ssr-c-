cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-Wall -Weffc++ -Wextra -Wsign-conversion -Wshadow -Werror=unused-variable -pedantic-errors -std=c++23 -g -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(enhance-ssr-example)

include_directories(/opt/homebrew/include lib)
link_directories(/opt/homebrew/lib)
find_package(extism-cpp REQUIRED)

add_executable(serve serve.cpp lib/wasm.cpp)
target_link_libraries(serve extism-cpp)
target_link_libraries(serve jsoncpp)
