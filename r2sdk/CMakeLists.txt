add_library(r2sdk SHARED "core/dllmain.cpp" "windows/console.cpp" "windows/console.h" "core/init.cpp")

target_precompile_headers(r2sdk PUBLIC "core/stdafx.h")

include_directories(.)