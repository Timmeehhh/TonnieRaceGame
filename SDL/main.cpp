//
//  main.cpp
//  SDL
//
//  Created by Delroy van der Kemp on 02/09/2016.
//  Copyright © 2016 42IN13SAg. All rights reserved.
//

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main(int argc, const char * argv[]) {
    SDL_Window* window = NULL;
    
    SDL_Surface* screenSurface = NULL;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( window == NULL )
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(4000);
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
