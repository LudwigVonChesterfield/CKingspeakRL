#pragma once

#include "components.hpp"
#include "clock.hpp"

struct Velocity{
    vec2int_t vector;
};

struct Acceleration{
    vec2int_t vector;
};

void handle_particles(registry& registry, int dt);
