#include "Coords.h"

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Coords::Coords(SDL_Window *window)
{
    windowWidth = SDL_GetWindowSurface(window)->w;
    windowHeight = SDL_GetWindowSurface(window)->h;
}

Vector2 Coords::TranslateFromPixelsToAbsolute(SDL_FPoint coordinates)
{
    Vector2 result;
    result.x = (2 * coordinates.x - windowHeight) / windowWidth;
    result.y = (2 * coordinates.y - windowHeight) / windowHeight;
    return result;
}

SDL_FPoint Coords::TranslateFromAbsoluteToPixels(Vector2 coordinates)
{
    SDL_FPoint result;
    result.x = coordinates.x * windowHeight * .5f + windowWidth * .5f;
    result.y = -coordinates.y * windowHeight * .5f + windowHeight * .5f;
    return result;
}