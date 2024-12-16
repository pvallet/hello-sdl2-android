# hello-sdl2-android-ios

This is a simple bootstrap project to start using SDL in Android and iOS with CMake

The project's source code is split into different files to show how CMake can help support more complex code base structures.

## Android
This project is an update of the hello world project here https://github.com/stephen47/android-sdl2-gradle-template, as I couldn't find a good way to integrate a CMake built C++ project to an android application.
It features a sample hello world using SDL and SDL_image.

The project has now been restructured to use a simple flow. To use it, simply open `android` as a project in Android Studio, then compile and run from there.

## iOS
Similarly to the Android setup, simply open the Xcode project under `ios` and you can compile and run from there.
When you add new files to `src`, you don't need to add them in the Xcode project, CMake will take care of it

The setup was inspired from:
- https://lazyfoo.net/tutorials/SDL/52_hello_mobile/ios_mac/index.php
- https://github.com/leetal/ios-cmake

## Desktop
Desktop also works for Windows, iOS and Linux. Just run

```
mkdir build
cd build
cmake ..
cmake --build .
cd ..
./build/hello_sdl2
```

The binary might be under its specific configuration, like `build/Debug/hello_sdl2` or `build/Release/hello_sdl2`