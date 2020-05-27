#add_mocked_test(program SOURCES ${CMAKE_SOURCE_DIR}/src/module.c MOCKS printf)
#add_mocked_test(AirDensity LINK_LIBRARIES m cmocka)

include(ExternalProject)
include(CMakePrintHelpers)

ExternalProject_Add(cmocka_ep
  GIT_REPOSITORY git://git.cryptomilk.org/projects/cmocka.git
  GIT_TAG cmocka-1.1.5
  BUILD_COMMAND $(MAKE)
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(cmocka_ep binary_dir)
ExternalProject_Get_Property(cmocka_ep SOURCE_DIR)
cmake_print_variables(binary_dir)
cmake_print_variables(SOURCE_DIR)

include_directories(${SOURCE_DIR}/include)

add_library(cmocka SHARED IMPORTED)
set_property(TARGET cmocka PROPERTY IMPORTED_LOCATION ${binary_dir}/src/libcmocka.so)
add_dependencies(cmocka cmocka_ep) 

add_executable(test_AirDensity test_AirDensity.c ../src/AirDensity.c ../src/AirDensity.h)
target_link_libraries(test_AirDensity cmocka m)
add_test(test_AirDensity test_AirDensity)

