# teeth-a-majigger\CMakeLists.txt


# Find all source and header files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

file(GLOB IMGUI_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/../external/imgui/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../external/imgui/backends/imgui_impl_glfw.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../external/imgui/backends/imgui_impl_opengl3.cpp"
)

# Add the main executable
add_executable(teeth-a-majigger ${SOURCES} ${IMGUI_SOURCES})

# Link libraries as needed
target_link_libraries(teeth-a-majigger PRIVATE
        glfw
        libglew_static
        glm
        ${OpenCV_LIBS}
        dlib::dlib
)

# Include directories
target_include_directories(teeth-a-majigger PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include/capture
        ${CMAKE_CURRENT_SOURCE_DIR}/include/processing
        ${CMAKE_CURRENT_SOURCE_DIR}/include/utils
        ${CMAKE_CURRENT_SOURCE_DIR}/include/visualisation
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glew-cmake/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glm
        ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/external/dlib
)