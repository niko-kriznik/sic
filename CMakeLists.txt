cmake_minimum_required(VERSION 3.15)

set(project_name "sic")
project(${project_name} CXX)

include(cmake/StandardProjectSettings.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_23)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# Caching
include(cmake/Cache.cmake)

# Compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Sanitizers
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# {fmt}
set(fmt_project "fmt")
project(${fmt_project} CXX)
add_library(${fmt_project})
target_link_libraries(${fmt_project} PRIVATE project_options)

# Raisin library
add_executable(${project_name})
target_link_libraries(
  ${project_name}
  PRIVATE project_options project_warnings ${fmt_project})

# Subdirectories
add_subdirectory(src)
add_subdirectory(vendor)
