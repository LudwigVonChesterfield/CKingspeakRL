#include "audible.hpp"
// dependency hell
#include "engine.hpp"

entity create_speech_popup(registry& registry, GridSpatial& gridSpatial, Looks& looks, Speaker& speaker, string text){
    vec2int_t absolute = Engine::engine.grid->grid2absolute(Engine::engine.window, gridSpatial.position);

    auto popup = registry.create();

    registry.emplace<Spatial>(popup, absolute.x, absolute.y);
    registry.emplace<Looks>(popup, text, looks.font, looks.size / 2, looks.background, looks.foreground);
    registry.emplace<Sprite>(popup, create_sprite(registry.get<Looks>(popup)));
    registry.emplace<Temporary>(popup, 3 SECONDS);
    registry.emplace<Velocity>(popup, 0, -50);

    return popup;
}

void speak(registry& registry, GridSpatial& gridSpatial, Looks& looks, Speaker& speaker, string text){
    if(registry.valid(speaker.popup) && speaker.popup != entt::null){
        registry.destroy(speaker.popup);
    }

    speaker.popup = create_speech_popup(registry, gridSpatial, looks, speaker, text);
}
