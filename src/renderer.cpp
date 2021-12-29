#include "renderer.hpp"

#include <stdio.h>

Sprite create_sprite(Looks looks){
    TTF_Font* font = TTF_OpenFont(looks.font.c_str(), looks.size);
    if (!font){
        printf("Failed to load font.\nTTF Error: %s\n", TTF_GetError());
    }

    auto text_surface = TTF_RenderUTF8_Shaded(font, looks.text.c_str(), looks.foreground, looks.background);
    if (!text_surface){
        printf("Failed to create text surface.\nTTF Error: %s\n", TTF_GetError());
    }

    TTF_CloseFont(font);

    auto *text_tex = SDL_CreateTextureFromSurface(Engine::engine.renderer, text_surface);
    if (!text_tex){
        printf("Failed to create text texture.\nTTF Error: %s\n", TTF_GetError());
    }

    SDL_FreeSurface(text_surface);

    Sprite sprite = Sprite();
    sprite.texture = text_tex;

    SDL_QueryTexture(sprite.texture, nullptr, nullptr, &sprite.rect.w, &sprite.rect.h);

    return sprite;
}

void render_entity(Spatial& spatial, Sprite& sprite){
    int new_x = spatial.position.x;
    int new_y = spatial.position.y;

    sprite.rect.x = new_x + (Engine::engine.grid->cell_x - sprite.rect.w) / 2;
    sprite.rect.y = new_y + (Engine::engine.grid->cell_y - sprite.rect.h) / 2;

    SDL_RenderCopy(Engine::engine.renderer, sprite.texture, nullptr, &sprite.rect);
}

void render_grid_entity(GridSpatial& gridSpatial, Sprite& sprite){
    vec2int_t absolute = Engine::engine.grid->grid2absolute(Engine::engine.window, gridSpatial.position);

    sprite.rect.x = absolute.x + (Engine::engine.grid->cell_x - sprite.rect.w) / 2;
    sprite.rect.y = absolute.y + (Engine::engine.grid->cell_y - sprite.rect.h) / 2;

    SDL_RenderCopy(Engine::engine.renderer, sprite.texture, nullptr, &sprite.rect);
}

void render_entities(registry& registry){
    registry.view<GridSpatial, Sprite>().each(render_grid_entity);
    registry.view<Spatial, Sprite>().each(render_entity);
}
