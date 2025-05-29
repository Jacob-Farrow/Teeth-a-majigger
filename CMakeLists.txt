cmake_minimum_required(VERSION 3.8)
project(TEETH VERSION 0.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(external/glfw)
add_subdirectory(external/glew-cmake)
add_subdirectory(external/glm)
add_subdirectory(external/dlib dlib_build)

# Include directories for the project
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glew-cmake/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glm
        ${CMAKE_SOURCE_DIR}/external/stb
        ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends
)

# Set the CMAKE_PREFIX_PATH to include the path where OpenCV is installed
set(CMAKE_PREFIX_PATH "C:/tools/opencv/build")

# Find OpenCV with flags to avoid GPU support
find_package(OpenCV REQUIRED NO_MODULE)
if (OpenCV_FOUND)
    message(STATUS "Found OpenCV: ${OpenCV_VERSION}")
else()
    message(FATAL_ERROR "OpenCV not found!")
endif()

# Include directories for OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(teeth-a-majigger ${SOURCES} ${IMGUI_SOURCES})
