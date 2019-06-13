cmake_minimum_required( VERSION 3.1)

project( dlclose C)

add_executable( dlclose
src/main.c
)

add_library( bar SHARED
src/bar.c
)

target_link_libraries( dlclose
-ldl
)

if( APPLE)
   set( CMAKE_SHARED_LINKER_FLAGS "-Wl,-export_dynamic")
else()
   set( CMAKE_SHARED_LINKER_FLAGS "-Wl,-export-global-symbols")
endif()

