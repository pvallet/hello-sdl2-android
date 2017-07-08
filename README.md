# hello-sdl2-android

## Synopsis

This project is an update of the hello world project here https://github.com/stephen47/android-sdl2-gradle-template, as I couldn't find a good way to integrate a CMake built C++ project to an android application.

## Requirements
- JDK and JRE 8
- Android SDK and NDK (with Android Build-tools 26.0.0 and Android Platform API 25, though these are configurable)
- ANDROID_HOME and ANDROID_NDK_HOME environment variables set (I did this in /etc/environment)

## Downloading dependencies

Download the latest source release from the SDL website:

https://www.libsdl.org/download-2.0.php

Unzip it, put the SDL2 folder in external and rename it to SDL2 so your project folder should look like this:
```
+ android
+ external
| + SDL2
```

Then copy the java interface SDLActivity to the android project:
```
cp external/SDL2/android-project/src/org/libsdl/app/SDLActivity.java android/app/src/main/java/org/libsdl/app/
```

There, it's done!

## Compiling the sample program

You can compile your program and then install it on a connected device with the following commands:
```
cd android
./gradlew assembleDebug
./gradlew installDebug
```

## Thanks

Most of the code here is inspired by these repositories:

https://github.com/stephen47/android-sdl2-gradle-template (Android + gradle)

https://github.com/suikki/simpleSDL/ (Android + CMake)

The example libSDL2 program which draws the square on screen was found at https://stackoverflow.com/questions/21890627/drawing-a-rectangle-with-sdl2/21903973#21903973.

The Google NDK example projects were very helpful: https://github.com/googlesamples/android-ndk
