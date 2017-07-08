cmake_minimum_required(VERSION 3.4.1)

string(TOLOWER ${CMAKE_BUILD_TYPE} ANDROID_BUILD_DIR)
set(DISTRIBUTION_DIR ${CMAKE_SOURCE_DIR}/android/distribution/android/SDL2/intermediates/ndkBuild)
set(SOURCE_FILES src/main.cpp)
set(SDL_LOCATION ${CMAKE_SOURCE_DIR}/external/SDL2)

add_library( SDL2 SHARED IMPORTED )
set_target_properties(SDL2 PROPERTIES IMPORTED_LOCATION
${DISTRIBUTION_DIR}/${ANDROID_BUILD_DIR}/obj/local/${ANDROID_ABI}/libSDL2.so)

include_directories(${SDL_LOCATION}/include)

add_library( main SHARED ${SDL_LOCATION}/src/main/android/SDL_android_main.c ${SOURCE_FILES} )

target_link_libraries( main SDL2 )