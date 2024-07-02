#include <iostream>
#include <SDL2/SDL.h>
#include "main.h"

int main()
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    window = SDL_CreateWindow("Meow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {

                case SDL_WINDOWEVENT_EXPOSED:
                    std::cout << "gaa" << std::endl;
                    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
                    SDL_RenderClear(renderer);
                    SDL_RenderPresent(renderer);
                    break;

                default:
                    break;
                }
            default:
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
    /*switch (event.window.type)
    {

    case SDL_WINDOWEVENT_EXPOSED:
        std::cout << "gaa" << std::endl;
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        break;

    default:
        break;
    }*/
}