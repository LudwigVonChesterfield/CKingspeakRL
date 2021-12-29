#pragma once

#include <entt/entt.hpp>

using entt::registry;
using entt::entity;

class Action{
public:
    virtual void perform(registry& registry, entity ent) = 0;
};
