#pragma once

#include <SDL2/SDL.h>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <entt/entt.hpp>
#include <stdio.h>
#include "interactable.hpp"
#include "action.hpp"
#include "concrete_actions.hpp"
#include "clock.hpp"

using entt::registry;
using entt::entity;
using std::map;
using std::set;
using std::swap;
using std::queue;

class ControlsHandler{
public:
    ControlsHandler();
    bool is_pressed(SDL_Keycode key);
    void press(registry& registry, SDL_Keycode key);
    void unpress(registry& registry, SDL_Keycode key);

    void handle_inputs(registry& registry, int dt);

private:
    int next_input = 0;
    int input_delay = 0.1 SECONDS;

    int next_input_tap = 0;
    int input_tap_delay = 0.1 SECONDS;

    set<SDL_Keycode> pressed_keys;
    map<SDL_Keycode, Action*> mapped_actions;
};
