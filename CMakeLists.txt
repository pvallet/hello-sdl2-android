cmake_minimum_required(VERSION 3.14.7 FATAL_ERROR)
cmake_policy(VERSION 3.14.7...3.28.1)

project(hello-sdl2-android-ios)

include(FetchContent)

FetchContent_Declare(
  SDL
  URL            https://github.com/libsdl-org/SDL/archive/refs/tags/release-2.30.8.zip
  SOURCE_DIR     ${CMAKE_BINARY_DIR}/external/SDL2
)

FetchContent_Declare(
  SDL_IMAGE
  URL            https://github.com/libsdl-org/SDL_image/archive/release-2.8.2.zip
  SOURCE_DIR     ${CMAKE_BINARY_DIR}/external/SDL2_image
)

FetchContent_MakeAvailable(SDL SDL_IMAGE)

# Copying needed files for the android project
set(SDL_ACTIVITY_FOLDER app/src/main/java/org/libsdl/app/)
file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/android/${SDL_ACTIVITY_FOLDER})
file(COPY ${CMAKE_BINARY_DIR}/external/SDL2/android-project/${SDL_ACTIVITY_FOLDER} DESTINATION ${CMAKE_SOURCE_DIR}/android/${SDL_ACTIVITY_FOLDER})
file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/android/app/src/main/assets/res)
file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_SOURCE_DIR}/android/app/src/main/assets)

set(SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_library( main SHARED ${SOURCE_FILES} )

target_link_libraries( main SDL2 SDL2_image )
