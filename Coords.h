#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
struct vec2
{
    float x;
    float y;
    vec2(float x = 0.f, float y = 0.f);
};

class Coords
{
private:
    int windowWidth;
    int windowHeight;

public:
    Coords(SDL_Window *window);
    Coords() = default;
    vec2 translateFromPixelsToAbsolute(SDL_FPoint coordinates);
    SDL_FPoint translateFromAbsoluteToPixels(vec2 coordinates);
    float getAspectRatio();
};