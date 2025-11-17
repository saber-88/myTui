cmake_minimum_required( VERSION 3.10)

project( TUI VERSION 1.0 LANGUAGES CXX)

set( CMAKE_CXX_STANDARD 20)
set( CMAKE_CXX_STANDARD_REQUIRED true)

find_package( fmt REQUIRED )

include_directories(
    include
)

add_executable (tui
    src/main.cpp
    src/include/screen.cpp
    src/include/component.cpp
    src/include/colors.cpp
)

target_link_libraries(tui PRIVATE fmt::fmt)