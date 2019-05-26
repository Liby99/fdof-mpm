cmake_minimum_required(VERSION 3.5)
project(mpm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++17")

set(FDOF_BUILD_TESTS false)
set(curr_dir ${CMAKE_CURRENT_LIST_DIR})
set(src_dir ${curr_dir}/src)

# Include the fdof library
add_subdirectory(lib/fdof EXCLUDE_FROM_ALL)
include_directories(lib/fdof/src/extern/)

# Include the eigen library
# add_subdirectory(lib/eigen EXCLUDE_FROM_ALL)
include_directories(lib/eigen/)

# Include directory
include_directories(src/)

file(GLOB_RECURSE mpm_sources ${src_dir}/*.cpp ${src_dir}/*.h)
set(mpm ${mpm_sources})
message("Sources...? ${mpm}")
add_library(mpm STATIC ${mpm})
target_link_libraries(mpm fdof)

file(GLOB_RECURSE test_sources tests/*.cpp)
foreach(test_source ${test_sources})
  string(REPLACE ".cpp" "" temp_path ${test_source})
  string(REPLACE "${CMAKE_CURRENT_LIST_DIR}/" "" temp_path ${temp_path})
  get_filename_component(temp_dir ${temp_path} DIRECTORY)
  get_filename_component(temp_name ${temp_path} NAME)
  add_executable(${temp_name} ${test_source})
  set_target_properties(${temp_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${temp_dir})
  target_link_libraries(${temp_name} mpm)
  include("${temp_dir}/CMakeLists.txt" OPTIONAL)
endforeach(test_source ${test_sources})