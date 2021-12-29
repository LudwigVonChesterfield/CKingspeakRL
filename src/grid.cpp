#include "grid.hpp"
// dependency hell
#include "engine.hpp"

Grid::Grid(int cell_x, int cell_y, int max_x, int max_y) : cell_x(cell_x), cell_y(cell_y), max_x(max_x), max_y(max_y){
}

bool Grid::is_tile_valid(int x, int y){
    if(x < 0 || x >= max_x){
        return false;
    }
    if(y < 0 ||y >= max_y){
        return false;
    }
    return true;
}

list<entity> Grid::get_colliders(registry& registry, int x, int y){
    list<entity> entities;

    auto view = registry.view<Collider, GridSpatial>();
    for(auto ent : view){
        auto& collider = view.get<Collider>(ent);
        auto& gridSpatial = view.get<GridSpatial>(ent);

        if(gridSpatial.position.x == x && gridSpatial.position.y == y){
            entities.push_back(ent);
        }
    }

    return entities;
}

vec2int_t Grid::grid2absolute(SDL_Window* window, vec2int_t pos){
    int w;
    int h;

    SDL_GetWindowSize(Engine::engine.window, &w, &h);

    int new_x = pos.x * w / max_x;
    int new_y = pos.y * h / max_y;

    return vec2int{new_x, new_y};
}
