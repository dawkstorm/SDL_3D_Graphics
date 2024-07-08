#include <iostream>
#include <SDL2/SDL.h>
#include "main.h"
#include <vector>
#include "Coords.h"
#include "Renderer.h"
#include "Cube.h"
static bool running = true;

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

    float moving = 0;

    window = SDL_CreateWindow("Meow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Coords coords(window);
    Renderer3D renderer3D(1.5f, &coords);
    Cube cube(&coords, &renderer3D);
    cube.setPos(vec3(-1.5f, 0, 0.f));

    bool resized = false;
    while (running)
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
            {
                running = false;
                break;
            }
            if (ev.type == SDL_KEYDOWN)
            {

                switch (ev.key.keysym.sym)
                {
                case SDLK_DOWN:
                    cube.setPos(vec3(cube.pos.x, cube.pos.y - 0.1f, cube.pos.z));
                    break;
                case SDLK_UP:
                    cube.setPos(vec3(cube.pos.x, cube.pos.y + 0.1f, cube.pos.z));
                    break;
                case SDLK_LEFT:
                    cube.setPos(vec3(cube.pos.x - 0.1f, cube.pos.y, cube.pos.z));
                    break;
                case SDLK_RIGHT:
                    cube.setPos(vec3(cube.pos.x + 0.1f, cube.pos.y, cube.pos.z));
                    break;
                case SDLK_g:
                    cube.setPos(vec3(cube.pos.x, cube.pos.y, cube.pos.z - 0.1f));
                    break;
                case SDLK_f:
                    cube.setPos(vec3(cube.pos.x, cube.pos.y, cube.pos.z + 0.1f));
                    break;

                case SDLK_u:
                    cube.rotate(vec3(-0.1f, 0, 0));
                    break;
                case SDLK_j:
                    cube.rotate(vec3(0.1f, 0, 0));
                    break;
                case SDLK_h:
                    cube.rotate(vec3(0, 0, 0.1f));
                    break;
                case SDLK_k:
                    cube.rotate(vec3(0, 0, -0.1f));
                    break;
                case SDLK_y:
                    cube.rotate(vec3(0, 0.1f, 0));
                    break;
                case SDLK_i:
                    cube.rotate(vec3(0, -0.1f, 0));
                    break;
                }
            }
            if (ev.type == SDL_WINDOWEVENT && ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
            {
                resized = true;
                break;
            }
        }

        if (resized)
        {
            resized = false;
            coords = Coords(window);
        }

        SDL_Color color = {0, 129, 12, 255};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        // SDL_RenderGeometry(renderer, nullptr, cube.get2DVerticies(color).data(), cube.get2DVerticies(color).size(), nullptr, 0);
        cube.renderVertecies(renderer, color);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}