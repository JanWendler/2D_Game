cmake_minimum_required(VERSION 3.21)


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Game.cpp Game.h GameWindow.cpp GameWindow.h SurfaceManager.h TextureManager.cpp TextureManager.h Coordinates.cpp Coordinates.h Map.cpp Map.h EntityComponentSystem.cpp EntityComponentSystem.h components/Components.h components/SpriteComponent.h components/TransformComponent.h Vector2D.cpp Vector2D.h components/KeyboardController.h components/ColliderComponent.h components/Collision.cpp components/Collision.h components/TileComponent.h components/Animation.h)
set(WINDOWS_EXE ${PROJECT_NAME})

add_executable(${WINDOWS_EXE} ${SOURCE_FILES})
#set_target_properties(${WINDOWS_EXE} PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
target_link_libraries(${WINDOWS_EXE} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} )