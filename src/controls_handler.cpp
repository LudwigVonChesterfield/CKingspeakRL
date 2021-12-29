#include "controls_handler.hpp"

ControlsHandler::ControlsHandler(){
    mapped_actions = {
        {SDLK_w, new PushAction(vec2int{0, -1}, 2)},
        {SDLK_a, new PushAction(vec2int{-1, 0}, 2)},
        {SDLK_s, new PushAction(vec2int{0, 1}, 2)},
        {SDLK_d, new PushAction(vec2int{1, 0}, 2)},
        {SDLK_SPACE, new SpeakAction("...")},
    };
}

bool ControlsHandler::is_pressed(SDL_Keycode key){
    return pressed_keys.count(key) > 0;
}

void ControlsHandler::press(registry& registry, SDL_Keycode key){
    pressed_keys.insert(key);

    if(next_input_tap > 0){
        return;
    }
    next_input_tap = input_tap_delay;
    next_input = input_delay;

    auto action_iterator = mapped_actions.find(key);
    if(action_iterator == mapped_actions.end()){
        return;
    }

    Action* key_action = action_iterator->second;

    auto view = registry.view<Interactable, Controlled>();

    for(auto ent : view){
        auto& interactable = view.get<Interactable>(ent);

        queue<Action*> empty;
        swap(interactable.planned, empty);

        if(!interactable.planned.empty()){
            continue;
        }

        interactable.planned.push(key_action);
    }
}

void ControlsHandler::unpress(registry& registry, SDL_Keycode key){
    pressed_keys.erase(key);
}

void ControlsHandler::handle_inputs(registry& registry, int dt){
    if(next_input_tap > 0){
        next_input_tap -= dt;
    }

    if(next_input > 0){
        next_input -= dt;
        return;
    }
    next_input = input_delay;

    auto view = registry.view<Interactable, Controlled>();

    for(auto ent : view){
        auto& interactable = view.get<Interactable>(ent);

        queue<Action*> empty;
        swap(interactable.planned, empty);

        for(auto & [key, action] : mapped_actions){
            if(!is_pressed(key)){
                continue;
            }

            // 1 action per "turn", currently.
            if(!interactable.planned.empty()){
                break;
            }

            interactable.planned.push(action);
        }
    }
}
