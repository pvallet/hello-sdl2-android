#!/bin/bash
BUILD_DIR=../build_ios

# Configure the project with the right toolchain in the same folder as this file
cmake -B $BUILD_DIR -G Xcode -DCMAKE_BUILD_TYPE=$CONFIGURATION -DCMAKE_TOOLCHAIN_FILE=$(dirname "$BASH_SOURCE")/ios.toolchain.cmake -DPLATFORM=OS64 -DENABLE_ARC=0 .. || exit 1

# Build the project
cmake --build $BUILD_DIR --target ALL_BUILD --config=$CONFIGURATION || exit 1
