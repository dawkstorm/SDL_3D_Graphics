#include "coords.h"

Point2D::Point2D(float x = 0.f, float y = 0.f)
{
    this->x = x;
    this->y = y;
}

coords::coords(SDL_Window *window)
{
    windowWidth = SDL_GetWindowSurface(window)->w;
    windowHeight = SDL_GetWindowSurface(window)->h;
}

Point2D coords::TranslateFromPixelsToAbsolute(SDL_FPoint coordinates)
{
    Point2D result;
    result.x = coordinates.x / windowWidth;
    result.y = coordinates.y / windowHeight;
    return result;
}

SDL_FPoint coords::TranslateFromAbsoluteToPixels(Point2D coordinates)
{
    SDL_FPoint result;
    result.x = coordinates.x * windowWidth * .5f + windowWidth * .5f;
    result.y = coordinates.y * windowWidth * .5f + windowHeight * .5f;
    return result;
}