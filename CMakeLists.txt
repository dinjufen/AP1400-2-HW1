cmake_minimum_required(VERSION 3.13)
project(AP)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
set(CMAKE_CXX_STANDARD 14)

enable_testing()
find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

include_directories(include/)

add_executable(main
        src/main.cpp
        src/hw1.cpp
        src/unit_test.cpp
)
target_link_libraries(main PRIVATE
        GTest::gtest
        GTest::gtest_main
        fmt::fmt
)

