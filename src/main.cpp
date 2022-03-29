#include <entt/entt.hpp>
#include <stdio.h>
#include "engine.hpp"
#include "components.hpp"
#include "palette.hpp"
#include "renderer.hpp"
#include "interactable.hpp"
#include "audible.hpp"
#include "saves.hpp"

using entt::registry;
using entt::entity;

int main(int argc, char** argv){
    auto exit_code = Engine::engine.init(900, 900, 15, 15);
    if(exit_code != 0){
        return exit_code;
    }

    auto main_registry = registry{};

    auto player_entity = main_registry.create();
    main_registry.emplace<GridSpatial>(player_entity, 7, 7);
    main_registry.emplace<Collider>(player_entity, 1);
    main_registry.emplace<Looks>(player_entity, "Я", Palette::font_path, Palette::font_size, Palette::white(), Palette::black());
    Looks& player_looks = main_registry.get<Looks>(player_entity);
    main_registry.emplace<Sprite>(player_entity, create_sprite(player_looks));
    main_registry.emplace<Interactable>(player_entity);
    main_registry.emplace<Controlled>(player_entity);
    main_registry.emplace<Speaker>(player_entity);

    auto box_entity = main_registry.create();
    main_registry.emplace<GridSpatial>(box_entity, 5, 5);
    main_registry.emplace<Collider>(box_entity, 1);
    main_registry.emplace<Looks>(box_entity, "Ш", Palette::font_path, Palette::font_size, Palette::orange(), Palette::black());
    main_registry.emplace<Sprite>(box_entity, create_sprite(main_registry.get<Looks>(box_entity)));
    main_registry.emplace<Interactable>(box_entity);

    auto wall_entity = main_registry.create();
    main_registry.emplace<GridSpatial>(wall_entity, 3, 3);
    main_registry.emplace<Collider>(wall_entity, 10);
    main_registry.emplace<Looks>(wall_entity, "■", Palette::font_path, Palette::font_size, Palette::grey(), Palette::grey());
    main_registry.emplace<Sprite>(wall_entity, create_sprite(main_registry.get<Looks>(wall_entity)));
    main_registry.emplace<Interactable>(wall_entity);

    for(int x = 0; x < Engine::engine.grid->max_x; x++){
        for(int y = 0; y < Engine::engine.grid->max_y; y++){
            auto dot_entity = main_registry.create();
            main_registry.emplace<GridSpatial>(dot_entity, x, y);
            main_registry.emplace<Looks>(dot_entity, ".", Palette::font_path, Palette::font_size, Palette::grey(), Palette::black());
            main_registry.emplace<Sprite>(dot_entity, create_sprite(main_registry.get<Looks>(dot_entity)));
        }
    }

    save_to_file(main_registry, "save.json");

    return Engine::engine.start(main_registry);
}
