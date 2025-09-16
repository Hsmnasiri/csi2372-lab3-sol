cmake_minimum_required(VERSION 3.12)
project(csi2372_lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(miniarray src/miniarray.cpp)
target_include_directories(miniarray PUBLIC include)

add_executable(ma_core tests/ma_core.cpp)
target_link_libraries(ma_core PRIVATE miniarray)

add_executable(ma_valuecats tests/ma_valuecats.cpp)
target_link_libraries(ma_valuecats PRIVATE miniarray)

add_library(debug_utils src/debug_utils.cpp)
target_include_directories(debug_utils PUBLIC include)

add_executable(dbg_tests tests/dbg_tests.cpp)
target_link_libraries(dbg_tests PRIVATE debug_utils)

add_library(auto_minitask src/auto_minitask.cpp)
target_include_directories(auto_minitask PUBLIC include)

add_executable(auto_task tests/auto_task.cpp)
target_link_libraries(auto_task PRIVATE auto_minitask)

include(CTest)
add_test(NAME ma_core      COMMAND $<TARGET_FILE:ma_core>)
add_test(NAME ma_valuecats COMMAND $<TARGET_FILE:ma_valuecats>)
add_test(NAME dbg_tests    COMMAND $<TARGET_FILE:dbg_tests>)
add_test(NAME auto_task COMMAND $<TARGET_FILE:auto_task>)
