
set(CMAKE_WIN32_EXECUTABLE True)

add_executable(r2launcher "main.cpp")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:8000000")

target_link_libraries(r2launcher PUBLIC Shlwapi)
