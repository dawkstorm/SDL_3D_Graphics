#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
struct Point2D
{
    float x;
    float y;
    Point2D(float x = 0.f, float y = 0.f);
};

class Coords
{
private:
    int windowWidth;
    int windowHeight;

public:
    Coords(SDL_Window *window);
    Coords() = default;
    Point2D TranslateFromPixelsToAbsolute(SDL_FPoint coordinates);
    SDL_FPoint TranslateFromAbsoluteToPixels(Point2D coordinates);
};