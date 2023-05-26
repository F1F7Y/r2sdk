cmake_minimum_required (VERSION 3.8)

project ("r2sdk")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VS_PLATFORM_TOOLSET v143)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/game)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/game)

include_directories(.)

add_subdirectory("r2launcher")
add_subdirectory("r2sdk")

set(HTTP_ONLY ON)
set(CURL_STATICLIB ON)

add_subdirectory("thirdparty/detours")
add_subdirectory("thirdparty/spdlog")
add_subdirectory("thirdparty/curl")