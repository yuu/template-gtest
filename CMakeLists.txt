cmake_minimum_required(VERSION 3.0.0)

project(ut VERSION 0.0.1)

set(APP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(TESTFW_LIB
    -lgtest
    -lgtest_main
    -lpthread
)

file(GLOB SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*_test.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${TESTFW_LIB})

add_custom_target(check ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
