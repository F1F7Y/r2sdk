cmake_minimum_required (VERSION 3.8)

project ("r2sdk")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/game)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/game)

include_directories(.)

add_subdirectory("r2launcher")
add_subdirectory("r2sdk")

add_subdirectory("thirdparty/detours")
add_subdirectory("thirdparty/spdlog")
