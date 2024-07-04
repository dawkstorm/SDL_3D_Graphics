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
    Renderer3D renderer3D(1.f, coords);
    Cube cube(coords, renderer3D);
    cube.setPos(Point3D(-1.5f, 1, 1.f));

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
                    cube.setPos(Point3D(cube.position.x, cube.position.y - 0.1f, cube.position.z));
                    break;
                case SDLK_UP:
                    cube.setPos(Point3D(cube.position.x, cube.position.y + 0.1f, cube.position.z));
                    break;
                case SDLK_LEFT:
                    cube.setPos(Point3D(cube.position.x - 0.1f, cube.position.y, cube.position.z));
                    break;
                case SDLK_RIGHT:
                    cube.setPos(Point3D(cube.position.x + 0.1f, cube.position.y, cube.position.z));
                    break;
                case SDLK_g:
                    cube.setPos(Point3D(cube.position.x, cube.position.y, cube.position.z - 0.1f));
                    break;
                case SDLK_f:
                    cube.setPos(Point3D(cube.position.x, cube.position.y, cube.position.z + 0.1f));
                    break;
                }
            }
        }

        /*std::vector<SDL_Vertex> verts =
            {
                {
                    coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(Point3D(0, 1, 0))),
                    SDL_Color{255, 0, 255, 255},
                    SDL_FPoint{0},
                },
                {
                    coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(Point3D(0, 0, 0))),
                    SDL_Color{255, 255, 255, 255},
                    SDL_FPoint{0},
                },
                {
                    coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(Point3D(1, 0, 0))),
                    SDL_Color{0, 255, 255, 255},
                    SDL_FPoint{0},
                },

                {
                    coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(Point3D(0, 1, 0))),
                    SDL_Color{255, 0, 255, 255},
                    SDL_FPoint{0},
                },
                {
                    coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(Point3D(1, 1, 0))),
                    SDL_Color{255, 255, 255, 255},
                    SDL_FPoint{0},
                },
                {
                    coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(Point3D(1, 0, 0))),
                    SDL_Color{0, 255, 255, 255},
                    SDL_FPoint{0},
                },
            };
        */

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderGeometry(renderer, nullptr, cube.get2DVerticies().data(), cube.get2DVerticies().size(), nullptr, 0);
        // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLines(renderer, cube.get2DEdges().data(), cube.get2DEdges().size());
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}