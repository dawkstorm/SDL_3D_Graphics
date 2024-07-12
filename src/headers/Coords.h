#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

/// @brief 2 dimensional vector
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
    /// @brief Constructor
    /// @param window Window
    Coords(SDL_Window *window);
    Coords() = default;

    /// @brief Translate coordinates in pixel into absolute
    /// @param coordinates Coordinates
    /// @return Vector2
    vec2 translateFromPixelsToAbsolute(SDL_FPoint coordinates);

    /// @brief Translate absolute coordinates into pixels on secreen
    /// @param coordinates Coordinates
    /// @return Vector2
    SDL_FPoint translateFromAbsoluteToPixels(vec2 coordinates);

    /// @brief Get aspect ratio of the screen height divided by width
    /// @return float
    float getAspectRatioHW();
};