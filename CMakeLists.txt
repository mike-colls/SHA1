cmake_minimum_required(VERSION 3.17)

option(SHA1_TESTS "Include sha1 library unit tests" TRUE)

add_library(sha1 STATIC)
target_sources(sha1 PRIVATE src/sha1.cpp include/sha1/sha1.hpp)
target_include_directories(sha1 PUBLIC include)
target_compile_features(sha1 PUBLIC cxx_std_20)

if(SHA1_TESTS)
add_executable(sha1_tests)
target_sources(sha1_tests PRIVATE src/sha1.test.cpp)
target_link_libraries(sha1_tests PRIVATE sha1)
add_test(sha1_tests sha1_tests)
endif()
