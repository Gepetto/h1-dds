cmake_minimum_required(VERSION 3.5)
project(unitre_cyclonedds VERSION 2.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT TARGET CycloneDDS::ddsc)
  # Find the CycloneDDS package.
  find_package(CycloneDDS REQUIRED)
endif()


list(APPEND CMAKE_PREFIX_PATH "/opt/unitree_robotics/lib/cmake")
find_package(unitree_sdk2 REQUIRED)


# This is a convenience function, provided by the CycloneDDS package,
# that will supply a library target related the the given idl file.
# In short, it takes the idl file, generates the source files with
# the proper data types and compiles them into a library.
idlc_generate(TARGET Messages FILES "messages/LowCmd.idl" "messages/LowState.idl" WARNINGS no-implicit-extensibility)

# Both executables have only one related source file.
add_executable(sdkless subscriber.c)
add_executable(sdkful subscriber_using_sdk.cpp)

# Both executables need to be linked to the idl data type library and
# the ddsc API library.
target_link_libraries(sdkless Messages unitree_sdk2 CycloneDDS::ddsc)
target_link_libraries(sdkful Messages unitree_sdk2 CycloneDDS::ddsc)
