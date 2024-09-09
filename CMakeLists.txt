cmake_minimum_required(VERSION 3.14)
project(COMS4157-demo)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CPPLINT "cpplint")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  car_test
  test/CarUnitTests.cpp
  src/Car.cpp
)

target_include_directories(car_test PRIVATE
    include
)

target_link_libraries(car_test PRIVATE
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(car_test)

# Find the cpplint program
find_program(CPPLINT cpplint)

if (CPPLINT)
    # List of source files to be checked by cpplint
    set(SOURCE_FILES
        src/main.cpp 
        src/Course.cpp 
        src/Department.cpp 
        src/MyFileDatabase.cpp 
        src/RouteController.cpp
        src/MyApp.cpp
        src/Globals.cpp
        test/sample.cpp
        test/CourseUnitTests.cpp
    )

    # Custom target to run cpplint
    add_custom_target(
        cpplint
        COMMAND ${CPPLINT} --filter=-whitespace,-build/include_what_you_use ${SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running cpplint for Google C++ Style Guide compliance"
    )
else()
    message(WARNING "cpplint not found! Skipping style checks.")
endif()
