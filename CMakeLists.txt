cmake_minimum_required( VERSION 3.10)

project( TUI VERSION 1.0 LANGUAGES CXX)

set( CMAKE_CXX_STANDARD 20)
set( CMAKE_CXX_STANDARD_REQUIRED true)


find_package( fmt REQUIRED )




add_executable (tui
    src/main.cpp
    include/src/screen.cpp
    include/src/component.cpp
    include/src/colors.cpp
)

target_include_directories( tui PRIVATE
    include
)
target_link_libraries(tui PRIVATE fmt::fmt)
