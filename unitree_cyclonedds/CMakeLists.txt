cmake_minimum_required(VERSION 3.5)
project(unitre_cyclonedds LANGUAGES C CXX )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


list(APPEND CMAKE_PREFIX_PATH "/opt/unitree_robotics/lib/cmake")
find_package(unitree_sdk2 REQUIRED)


if (NOT TARGET CycloneDDS-CXX::ddscxx)
  find_package(CycloneDDS-CXX REQUIRED)
endif()

if (NOT TARGET CycloneDDS::ddsc)
  find_package(CycloneDDS REQUIRED)
endif()

# This is a convenience function, provided by the CycloneDDS package,
# that will supply a library target related the the given idl file.
# In short, it takes the idl file, generates the source files with
# the proper data types and compiles them into a library.
idlcxx_generate(TARGET MessagesCXX FILES "messages/LowCmd.idl" "messages/LowState.idl" WARNINGS no-implicit-extensibility)
idlc_generate(TARGET MessagesC FILES "messages/LowCmd.idl" "messages/LowState.idl" WARNINGS no-implicit-extensibility)

# Both executables have only one related source file.
add_executable(sdkless subscriber.c)
add_executable(sdkful subscriber_using_sdk.cpp)

# Both executables need to be linked to the idl data type library and
# the ddsc API library.
target_link_libraries(sdkless MessagesC unitree_sdk2 CycloneDDS::ddsc)
# don't link cycloneddscxx, unitree_sdk2 bundles its own
target_link_libraries(sdkful MessagesCXX unitree_sdk2 )
