#include <SDL2/SDL.h>
#include <vector>
struct Point2D;

class coords
{
private:
    int windowWidth;
    int windowHeight;
    float aspectRatio;

public:
    coords(SDL_Window *window);
    Point2D TranslateFromPixelsToAbsolute(SDL_FPoint coordinates);
    SDL_FPoint TranslateFromAbsoluteToPixels(Point2D coordinates);
};