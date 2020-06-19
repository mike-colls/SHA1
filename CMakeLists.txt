cmake_minimum_required(VERSION 3.17)

add_library(sha1 STATIC)
target_sources(sha1 PRIVATE sha1.cpp sha1.hpp)
target_include_directories(sha1 PUBLIC .)
target_compile_features(sha1 PUBLIC cxx_std_17) # cxx_std_20

add_executable(sha1_tests)
target_sources(sha1_tests PRIVATE tests.cpp sha1.hpp sha1_calculator.hpp)
target_link_libraries(sha1_tests PRIVATE sha1)
add_test(sha1_tests sha1_tests)
