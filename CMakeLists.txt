cmake_minimum_required(VERSION 3.13)

project(magnum-resource-loading-crash-demo)
set(CMAKE_CXX_STANDARD 14)

set(CORRADE_BUILD_STATIC ON CACHE BOOL "" FORCE)
set(MAGNUM_BUILD_STATIC ON CACHE BOOL "" FORCE)
set(BUILD_STATIC ON)

add_subdirectory(corrade EXCLUDE_FROM_ALL)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/corrade/modules;${CMAKE_SOURCE_DIR}/magnum/modules;${CMAKE_MODULE_PATH})
message("cmake module path is ${CMAKE_MODULE_PATH}")
add_subdirectory(magnum EXCLUDE_FROM_ALL)

set(CORRADE_WITH_UTILITY ON CACHE BOOL "" FORCE)
set(CORRADE_BUILD_MULTITHREADED ON CACHE BOOL "" FORCE)
find_package(Corrade REQUIRED Utility)

set(MAGNUM_TARGET_GL ON CACHE BOOL "" FORCE)
set(MAGNUM_WITH_SHADERS ON CACHE BOOL "" FORCE)

find_package(Magnum REQUIRED GL Shaders)

include_directories(include)
add_library(demo-lib SHARED src/library.cpp)
target_link_libraries(demo-lib Corrade::Main Magnum::Magnum Magnum::GL Magnum::Shaders)

add_executable(demo src/main.cpp)
target_link_libraries(demo demo-lib)
