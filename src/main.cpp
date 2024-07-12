#include <iostream>
#include <SDL2/SDL.h>
#include "headers/main.h"
#include <vector>
#include "headers/Coords.h"
#include "headers/Renderer.h"
#include "headers/Cube.h"
#include "headers/Pyramid.h"
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
    window = SDL_CreateWindow("3d graphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Coords coords(window);
    Renderer3D renderer3D(1.5f, &coords);

    Cube cube(&coords, &renderer3D);
    cube.setPos(vec3(1.5f, 0, 17.5f));

    Pyramid pyramid(&coords, &renderer3D);
    pyramid.setPos(vec3(-1, 0, 7));

    bool resized = false;
    vec3 *cam = &renderer3D.cameraPos;
    float angle = 45.f;
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
                    *cam = vec3(cam->x, cam->y - 0.1f, cam->z);
                    cube.updateVertex();
                    break;
                case SDLK_UP:
                    *cam = vec3(cam->x, cam->y + 0.1f, cam->z);
                    cube.updateVertex();
                    break;
                case SDLK_LEFT:
                    *cam = vec3(cam->x - 0.1f, cam->y, cam->z);
                    cube.updateVertex();
                    break;
                case SDLK_RIGHT:
                    *cam = vec3(cam->x + 0.1f, cam->y, cam->z);
                    cube.updateVertex();
                    break;
                case SDLK_g:
                    *cam = vec3(cam->x, cam->y, cam->z - 0.1f);
                    cube.updateVertex();
                    break;
                case SDLK_f:
                    *cam = vec3(cam->x, cam->y, cam->z + 0.1f);
                    cube.updateVertex();
                    break;
                }
                cube.rotateByKeys(&ev);
                pyramid.rotateByKeys(&ev);
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
        // cube.rotate(vec3(-.001f, 0.001f, 0.f));
        SDL_Color color = {0, 255, 0, 255};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        cube.render(renderer, color);
        pyramid.render(renderer, color);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}