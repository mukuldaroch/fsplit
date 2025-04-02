cmake_minimum_required(VERSION 3.10)
project(fsplit)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include third_party/imgui third_party/sdl2)

# Find OS-specific dependencies
if(WIN32)
    set(SYSTEM_LIBS ws2_32)  # Windows networking library (if needed)
elseif(UNIX)
    set(SYSTEM_LIBS pthread)  # Linux threading
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/splitter.cpp
    src/combiner.cpp
    src/ui.cpp
    src/utils.cpp
)

# Add executable
add_executable(fsplit ${SOURCES})

# Link system libraries
target_link_libraries(fsplit ${SYSTEM_LIBS})
