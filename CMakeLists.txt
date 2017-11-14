cmake_minimum_required(VERSION 3.0.0)

project(ut VERSION 0.0.1)
enable_testing()

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

add_test(
    NAME ${PROJECT_NAME}
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test
)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
    --force-new-ctest-process
    --output-on-failure
)
