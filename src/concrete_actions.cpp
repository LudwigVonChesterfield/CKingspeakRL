#include "concrete_actions.hpp"
//dependency hell
#include "engine.hpp"

MoveAction::MoveAction(vec2int_t vec) : vec(vec){
}

void MoveAction::perform(registry& registry, entity ent){
    auto& gridSpatial = registry.get<GridSpatial>(ent);
    int new_x = gridSpatial.position.x + vec.x;
    int new_y = gridSpatial.position.y + vec.y;

    if(!Engine::engine.grid->is_tile_valid(new_x, new_y)){
        return;
    }

    if(registry.try_get<Collider>(ent) != nullptr){
        list<entity> colliders = Engine::engine.grid->get_colliders(registry, new_x, new_y);
        if(!colliders.empty()){
            return;
        }
    }

    gridSpatial.position.x = new_x;
    gridSpatial.position.y = new_y;
}

PushAction::PushAction(vec2int_t vec, int force) : vec(vec), force(force){
}

void PushAction::perform(registry& registry, entity ent){
    if(force <= 0){
        return;
    }

    auto& gridSpatial = registry.get<GridSpatial>(ent);
    int new_x = gridSpatial.position.x + vec.x;
    int new_y = gridSpatial.position.y + vec.y;

    if(!Engine::engine.grid->is_tile_valid(new_x, new_y)){
        return;
    }

    if(registry.try_get<Collider>(ent) != nullptr){
        list<entity> colliders = Engine::engine.grid->get_colliders(registry, new_x, new_y);
        for(auto collider : colliders){
            auto& collider_collider = registry.get<Collider>(collider);
            PushAction* collider_push = new PushAction(vec, force - collider_collider.weight);
            collider_push->perform(registry, collider);
        }

        colliders = Engine::engine.grid->get_colliders(registry, new_x, new_y);
        if(!colliders.empty()){
            return;
        }
    }

    MoveAction* move_action = new MoveAction(vec);
    move_action->perform(registry, ent);
}

SpeakAction::SpeakAction(string text) : text(text){
}

void SpeakAction::perform(registry& registry, entity ent){
    auto& gridSpatial = registry.get<GridSpatial>(ent);
    auto& looks = registry.get<Looks>(ent);
    auto& speaker = registry.get<Speaker>(ent);

    speak(registry, gridSpatial, looks, speaker, text);
}
