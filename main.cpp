#include <iostream>
#include <SDL2/SDL.h>
#include "main.h"
#include <vector>
#include "coords.h"

static bool running = true;

void PollEvents(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
        if (ev.type == SDL_QUIT)
        {
            running = false;
            break;
        }
    }
}

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

    window = SDL_CreateWindow("Meow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    coords coords(window);

    const std::vector<SDL_Vertex> verts =
        {
            {
                coords.TranslateFromAbsoluteToPixels(Point2D(-1, -1)),
                SDL_Color{255, 0, 255, 255},
                SDL_FPoint{0},
            },
            {
                coords.TranslateFromAbsoluteToPixels(Point2D(-1, 0)),
                SDL_Color{255, 255, 255, 255},
                SDL_FPoint{0},
            },
            {
                coords.TranslateFromAbsoluteToPixels(Point2D(0, 0)),
                SDL_Color{0, 255, 255, 255},
                SDL_FPoint{0},
            },
        };

    while (running)
    {
        PollEvents(window, renderer);

        SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderGeometry(renderer, nullptr, verts.data(), verts.size(), nullptr, 0);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}