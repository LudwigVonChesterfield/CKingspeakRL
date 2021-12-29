#pragma once

#include <entt/entt.hpp>
#include <string>
#include <list>
#include <queue>
#include "action.hpp"
#include "vec2int.hpp"
#include "components.hpp"
#include "audible.hpp"

using entt::registry;
using entt::entity;
using std::queue;
using std::swap;
using std::string;

class MoveAction : public Action{
public:
    MoveAction(vec2int_t vec);
    void perform(registry& registry, entity ent);

private:
    vec2int_t vec;
};

class PushAction : public Action{
public:
    PushAction(vec2int_t vec, int force);
    void perform(registry& registry, entity ent);

private:
    vec2int_t vec;
    int force;
};

class SpeakAction : public Action{
public:
    SpeakAction(string text);
    void perform(registry& registry, entity ent);

private:
    string text;
};
