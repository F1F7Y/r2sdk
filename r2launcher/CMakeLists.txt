
set(CMAKE_WIN32_EXECUTABLE True)

add_executable(r2launcher "main.cpp")

target_link_libraries(r2launcher PUBLIC Shlwapi)
