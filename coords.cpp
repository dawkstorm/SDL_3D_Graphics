#include "Coords.h"

vec2::vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Coords::Coords(SDL_Window *window)
{
    windowWidth = SDL_GetWindowSurface(window)->w;
    windowHeight = SDL_GetWindowSurface(window)->h;
}

vec2 Coords::translateFromPixelsToAbsolute(SDL_FPoint coordinates)
{
    vec2 result;
    result.x = (2 * coordinates.x - windowHeight) / windowWidth;
    result.y = (2 * coordinates.y - windowHeight) / windowHeight;
    return result;
}

SDL_FPoint Coords::translateFromAbsoluteToPixels(vec2 coordinates)
{
    SDL_FPoint result;
    result.x = coordinates.x * windowHeight * .5f + windowWidth * .5f;
    result.y = -coordinates.y * windowHeight * .5f + windowHeight * .5f;
    return result;
}

float Coords::getAspectRatio()
{
    float aspectRatio = (float)windowWidth / (float)windowHeight;
    return aspectRatio;
}