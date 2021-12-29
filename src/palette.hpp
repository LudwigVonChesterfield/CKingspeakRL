#pragma once

#include <SDL2/SDL.h>

struct Palette
{
    static constexpr auto font_path = "res/Tahoma Regular Font.ttf";
    static constexpr int font_size = 48;
    static constexpr int cell_width = 60;
    static constexpr int cell_height = 60;

    static constexpr SDL_Color black() { return {40, 44, 52, 255}; }
    static constexpr SDL_Color white() { return {171, 178, 191, 255}; }
    static constexpr SDL_Color grey()  { return {73, 81, 98, 255}; }
    static constexpr SDL_Color orange() { return {241, 143, 1, 255}; }
    static constexpr SDL_Color red() { return {221, 45, 74, 255}; }
    static constexpr SDL_Color gold() { return {230, 175, 46, 255}; }
    static constexpr SDL_Color green() { return {90, 255, 21, 255}; }
    static constexpr SDL_Color dark_green() { return {79, 119, 45, 255}; }
    static constexpr SDL_Color peach() { return {221, 252, 173, 255}; }
};
