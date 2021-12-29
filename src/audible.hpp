#pragma once

#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <string>
#include "components.hpp"
#include "palette.hpp"
#include "temporary.hpp"
#include "particles.hpp"
#include "clock.hpp"

using entt::registry;
using entt::entity;
using std::string;

struct Speaker{
    entity popup = entt::null;
};

entity create_speech_popup(registry& registry, GridSpatial& gridSpatial, Looks& looks, Speaker& speaker, string text);
void speak(registry& registry, GridSpatial& gridSpatial, Looks& looks, Speaker& speaker, string text);
