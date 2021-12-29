#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <entt/entt.hpp>
#include "components.hpp"
#include "palette.hpp"
#include "engine.hpp"
#include "vec2int.hpp"

using entt::registry;
using entt::entity;

Sprite create_sprite(Looks looks);
void render_entity(Spatial& spatial, Sprite& sprite);
void render_grid_entity(GridSpatial& gridSpatial, Sprite& sprite);
void render_entities(registry& registry);
