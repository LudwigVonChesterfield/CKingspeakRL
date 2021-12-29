#pragma once

#include <queue>
#include <entt/entt.hpp>
#include "action.hpp"

using entt::registry;
using entt::entity;
using std::queue;

void enact_plans(registry& registry);

struct Interactable{
    queue<Action*> planned;
};
