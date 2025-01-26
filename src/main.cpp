#include <SDL.h> // Needed to properly handle main() on iOS

#include "hello_world.h"

int main(int /*argc*/, char* /*argv*/[]) {
    // This function is extracted into another file to show how to call a project function as the iOS project includes main directly
    // The project is built using CMake and available as a library
    return hello_world();
}
