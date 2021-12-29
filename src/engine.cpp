#include "engine.hpp"

Engine Engine::engine;

int Engine::init(int width, int height, int max_x, int max_y){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Kingspeak", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1)
    {
        printf("Error: TTF failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    event_handler = new EventHandler();
    controls_handler = new ControlsHandler();

    clock = new Clock();

    grid = new Grid(Palette::cell_width, Palette::cell_height, max_x, max_y);

    return 0;
}

int Engine::start(registry &registry){
    running = true;

    SDL_Color background_color = Palette::black();

    SDL_SetRenderDrawColor(
        renderer,
        background_color.r,
        background_color.g,
        background_color.b,
        background_color.a
    );

    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            event_handler->handle_event(registry, event);
        }

        SDL_RenderClear(renderer);
        render_entities(registry);
        SDL_RenderPresent(renderer);

        if(!clock->should_tick()){
            continue;
        }
        clock->tick();

        handle_temporary(registry, clock->dt());
        handle_particles(registry, clock->dt());

        controls_handler->handle_inputs(registry, clock->dt());
        enact_plans(registry);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;

    TTF_Quit();

    SDL_Quit();

    return 0;
}

void Engine::stop(){
    running = false;
}
