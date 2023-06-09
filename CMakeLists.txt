cmake_minimum_required(VERSION 3.18)
project(BookShelf VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
include_directories(include
                    externals/sqlite3)
add_subdirectory(externals/sqlite3)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "source/*.cpp")
add_executable(BookShelf ${SOURCES})
target_link_libraries(BookShelf sqlite3)