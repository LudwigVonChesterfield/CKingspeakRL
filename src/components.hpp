#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <entt/entt.hpp>
#include "palette.hpp"
#include "vec2int.hpp"

using entt::registry;
using entt::entity;
using std::string;

struct GridSpatial{
    vec2int_t position;
};

struct Spatial{
    vec2int_t position;
};

struct Collider{
    int weight;
};

struct Looks{
    string text;
    string font;
    int size;
    SDL_Color foreground;
    SDL_Color background;
};

struct Sprite{
    SDL_Texture* texture;
    SDL_Rect rect;
};

struct Controlled{
};
