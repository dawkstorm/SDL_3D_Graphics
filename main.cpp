#include <iostream>
#include <SDL2/SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        SDL_Window *window = SDL_CreateWindow("Meow", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
        SDL_Delay(5000);
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
    return 0;
}