# Specify the minimum version.
cmake_minimum_required(VERSION 3.9)

# Specify the project info.
project(my_lib VERSION 1.0.0 DESCRIPTION "compute matrix determinant library")

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    source/computeDeterminant.cpp
    source/computeDeterminant.hpp
)

# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE source)

# Set the version property.
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER source/computeDeterminant.hpp)

# For access to standard installation directory variables (CMAKE_INSTALL_xDIR).
include(GNUInstallDirs)
# Set library shared object and API header file to install.
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)