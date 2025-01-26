#include "hello_world.h"

#include <SDL.h>
#include <SDL_image.h>

int hello_world(void) {
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "An SDL2 window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        360,
        640,
        SDL_WINDOW_OPENGL
    );
    if (window == NULL) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    if( renderer == NULL ) {
        SDL_Log( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return 1;
    }

    SDL_Surface *loadedImage = IMG_Load("res/hello.png");
    if (loadedImage == NULL) {
        SDL_Log("Could not find file: res/hello.png");
        return 1;
    }

    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = loadedImage->w;
    r.h = loadedImage->h;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
    if (texture == NULL) {
        SDL_Log("Could not create texture: %s\n", SDL_GetError());
        return 1;
    }
    SDL_FreeSurface(loadedImage);

    // Main loop flag
    bool quit = false;

    SDL_Event e;

    while( !quit ) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        // Set render color to red ( background will be rendered in this color )
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

        // Clear window
        SDL_RenderClear( renderer );

        // Render our image
        SDL_RenderCopy(renderer, texture, NULL, &r);

        // Render the rect to the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
