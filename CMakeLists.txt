cmake_minimum_required(VERSION 3.6)
project(SnakeAI)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(OPENGL_FILE E:/c++lib/OpenGL)
INCLUDE_DIRECTORIES(${OPENGL_FILE}/INCLUDE)
include_directories(include)
include_directories(lib)
link_directories(${OPENGL_FILE}/LIB)

set(SOURCE_FILES src/main.cpp
        include/Snake.h include/Direction.h include/Board.h src/Pos.cpp
        include/Pos.h src/Point.cpp include/Point.h src/SnakeManager.cpp
        include/SnakeManager.h include/util.h
        src/Board.cpp src/Snake.cpp)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_executable(SnakeAI ${SOURCE_FILES})


set(TARGET_LIB
        "E:/c++lib/OpenGL/LIB/GlU32.LIB"
        "E:/c++lib/OpenGL/LIB/OpenGL32.lib"
        "E:/c++lib/OpenGL/LIB/glut32.lib"
        )

target_link_libraries(SnakeAI ${TARGET_LIB})