#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
struct Vector2
{
    float x;
    float y;
    Vector2(float x = 0.f, float y = 0.f);
};

class Coords
{
private:
    int windowWidth;
    int windowHeight;

public:
    Coords(SDL_Window *window);
    Coords() = default;
    Vector2 TranslateFromPixelsToAbsolute(SDL_FPoint coordinates);
    SDL_FPoint TranslateFromAbsoluteToPixels(Vector2 coordinates);
};