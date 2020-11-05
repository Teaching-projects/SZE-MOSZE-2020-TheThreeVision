cmake_minimum_required(VERSION 2.6)
 

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# and the GTest and pthread library
add_executable(runTests unit_test.cpp ../JSON.cpp ../Hero.cpp ../Monster.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)


