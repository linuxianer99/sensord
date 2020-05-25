include(CMakePrintHelpers)

FIND_PACKAGE(Git)

if (NOT GIT_FOUND)
    error("Git not found !!")
endif()

EXECUTE_PROCESS(
       COMMAND ${GIT_EXECUTABLE} describe --tags --dirty
       OUTPUT_VARIABLE GIT_DESCRIBE_VERSION
       RESULT_VARIABLE GIT_DESCRIBE_RESULT
       ERROR_VARIABLE GIT_DESCRIBE_ERROR
       OUTPUT_STRIP_TRAILING_WHITESPACE
   )

add_definitions(-DVERSION_GIT=\"${GIT_DESCRIBE_VERSION}\")


add_executable(sensord main.c ms5611.c ams5915.c ads1110.c nmea.c timer.c KalmanFilter1d.c cmdline_parser.c configfile_parser.c vario.c AirDensity.c 24c16.c
)
target_link_libraries(sensord m)