cmake_minimum_required(VERSION 3.18.0)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project(tic-tac-toe VERSION 0.1.0)
set(CMAKE_C_STANDARD_REQUIRED 17)

find_package(cmocka CONFIG REQUIRED)
include(CTest)
enable_testing()

add_subdirectory(src/gamelib)
add_subdirectory(test/gamelib)
add_subdirectory(src/termgame)
add_subdirectory(test/termgame)
