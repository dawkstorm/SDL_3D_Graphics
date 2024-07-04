#include "coords.h"
struct Point2D
{
    float x;
    float y;
    Point2D(float x = 0, float y = 0);
};

Point2D::Point2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

coords::coords(SDL_Window *window)
{
    windowWidth = SDL_GetWindowSurface(window)->w;
    windowHeight = SDL_GetWindowSurface(window)->h;
    aspectRatio = windowWidth / windowHeight;
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
    result.x = coordinates.x * windowWidth;
    result.y = coordinates.y * windowHeight;
    return result;
}