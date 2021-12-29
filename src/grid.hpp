#pragma once

#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <list>
#include "components.hpp"
#include "vec2int.hpp"

using entt::registry;
using entt::entity;
using std::list;

/*
    TO-DO:
        - use vec2int_t cell_size instead of cell_x, cell_y
        - same for max dimensions
*/

class Grid{
public:
    int cell_x;
    int cell_y;
    int max_x;
    int max_y;

    Grid(int cell_x, int cell_y, int max_x, int max_y);

    bool is_tile_valid(int x, int y);
    list<entity> get_colliders(registry& registry, int x, int y);
    vec2int_t grid2absolute(SDL_Window* window, vec2int_t pos);

private:

};
