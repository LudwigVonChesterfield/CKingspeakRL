#pragma once

#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include "controls_handler.hpp"

using entt::registry;
using entt::entity;

class EventHandler{
public:
    void handle_event(registry& registry, SDL_Event event);
};
