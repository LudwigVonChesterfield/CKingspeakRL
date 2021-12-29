#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <entt/entt.hpp>
#include <stdio.h>
#include <vector>
#include "event_handler.hpp"
#include "controls_handler.hpp"
#include "grid.hpp"
#include "clock.hpp"
#include "palette.hpp"
#include "renderer.hpp"
#include "temporary.hpp"
#include "particles.hpp"

using entt::registry;
using entt::entity;
using std::vector;

class Engine{
public:
    int init(int width, int height, int max_x, int max_y);
    int start(registry &registry);
    void stop();

    static Engine engine; 

    EventHandler* event_handler;
    ControlsHandler* controls_handler;

    SDL_Renderer* renderer;
    SDL_Window* window;

    Clock* clock;
    Grid* grid;

private:
    bool running = false;
};
