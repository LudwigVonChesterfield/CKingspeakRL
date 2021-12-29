#include "event_handler.hpp"
//dependency hell
#include "engine.hpp"

void EventHandler::handle_event(registry& registry, SDL_Event event){
    switch(event.type){
        case SDL_QUIT:
            Engine::engine.stop();
            break;

        case SDL_KEYDOWN:
            Engine::engine.controls_handler->press(registry, event.key.keysym.sym);
            break;

        case SDL_KEYUP:
            Engine::engine.controls_handler->unpress(registry, event.key.keysym.sym);
            break;

        default:
            break;
    }
}
