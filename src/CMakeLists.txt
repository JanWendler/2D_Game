cmake_minimum_required(VERSION 3.21)

set(SOURCE_FILES main.cpp Game.cpp Game.h GameWindow.cpp GameWindow.h Error.cpp)

find_package(SDL2 REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(WINDOWS_EXE ${PROJECT_NAME})
add_executable(${WINDOWS_EXE} ${SOURCE_FILES})
set_target_properties(${WINDOWS_EXE} PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
target_link_libraries(${WINDOWS_EXE} ${SDL2_LIBRARIES})