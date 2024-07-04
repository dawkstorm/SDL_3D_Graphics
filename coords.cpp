#include "Coords.h"

Point2D::Point2D(float x, float y)
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
    result.x = (2 * coordinates.x - windowHeight) / windowWidth;
    result.y = (2 * coordinates.y - windowHeight) / windowHeight;
    return result;
}

SDL_FPoint coords::TranslateFromAbsoluteToPixels(Point2D coordinates)
{
    SDL_FPoint result;
    result.x = coordinates.x * windowHeight * .5f + windowWidth * .5f;
    result.y = -coordinates.y * windowHeight * .5f + windowHeight * .5f;
    return result;
}