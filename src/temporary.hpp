#pragma once

#include <entt/entt.hpp>

using entt::registry;
using entt::entity;

struct Temporary{
    int time_to_live;
};

void handle_temporary(registry& registry, int dt);
