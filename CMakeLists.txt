add_library(sha1 INTERFACE)
target_include_directories(sha1 INTERFACE .)

add_executable(sha1_tests tests.cpp)
target_link_libraries(sha1_tests PRIVATE sha1)
add_test(sha1_tests sha1_tests)
