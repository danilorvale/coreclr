cmake_minimum_required(VERSION 2.8.12.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES
  pal_except_filter.c
)

add_executable(paltest_pal_except_filter_ex_test3
  ${SOURCES}
)

add_dependencies(paltest_pal_except_filter_ex_test3 CoreClrPal)

target_link_libraries(paltest_pal_except_filter_ex_test3
  pthread
  m
  CoreClrPal
)
