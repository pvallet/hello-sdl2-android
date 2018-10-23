# hello-sdl2-android

## Synopsis

This project is an update of the hello world project here https://github.com/stephen47/android-sdl2-gradle-template, as I couldn't find a good way to integrate a CMake built C++ project to an android application.
It features a sample hello world using SDL and SDL_image.

## Requirements
- JDK and JRE 8
- Android SDK and NDK (with Android Build-tools 26.0.0 and Android Platform API 25, though these are configurable)
- ANDROID_HOME and ANDROID_NDK_HOME environment variables set (I did this in /etc/environment)

## Compiling the sample program (command line)

You can download the dependencies (SDL2 and SDL2_image), compile your program and then install it on a connected device with the following commands:
```
./get_dependencies
cd android
./gradlew assembleDebug
./gradlew installDebug
```

## Compiling the sample program (Android Studio)

As above, download the dependencies (SDL2 and SDL2_image), then open the ./android folder as an existing project in Android Studio:

## Downloading dependencies manually

Download the latest source release from SDL and SDL_image websites:

https://www.libsdl.org/download-2.0.php
https://www.libsdl.org/projects/SDL_image/

Unzip it, put the SDL2-x.x.x and SDL2_image-x.x.x folders in `external/SDL2` and rename them to SDL2 and SDL2_image so your project folder looks like this:
```
+ android
+ external
| + SDL2
| | + Android.mk
| | | SDL2
| | | SDL2_image
```

There, it's done!

## Thanks

Most of the code here is inspired by these repositories:

https://github.com/stephen47/android-sdl2-gradle-template (Android + gradle)

https://github.com/suikki/simpleSDL/ (Android + CMake)

The example libSDL2 program which draws the square on screen was found at https://stackoverflow.com/questions/21890627/drawing-a-rectangle-with-sdl2/21903973#21903973.

The Google NDK example projects were very helpful: https://github.com/googlesamples/android-ndk
