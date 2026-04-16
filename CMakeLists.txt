cmake_minimum_required(VERSION 3.15)
project(OpenGLPhysics)

set(CMAKE_CXX_STANDARD 17)

# ------------------------
# GLFW (from source)
# ------------------------
add_subdirectory(external/glfw-3.4)

# ------------------------
# GLAD
# ------------------------
add_library(glad external/src/glad.c)
target_include_directories(glad PUBLIC external/include)

# ------------------------
# Your executable
# ------------------------
add_executable(app main.cpp)

# ------------------------
# Link everything
# ------------------------
target_link_libraries(app glfw glad)

# Windows OpenGL
if (WIN32)
    target_link_libraries(app opengl32)
endif()