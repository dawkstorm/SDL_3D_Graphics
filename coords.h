#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
class Point2D
{
public:
    float x;
    float y;
    Point2D(float x, float y);
};

class coords
{
private:
    int windowWidth;
    int windowHeight;

public:
    coords(SDL_Window *window);
    Point2D TranslateFromPixelsToAbsolute(SDL_FPoint coordinates);
    SDL_FPoint TranslateFromAbsoluteToPixels(Point2D coordinates);
};