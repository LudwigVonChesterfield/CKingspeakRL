#include "particles.hpp"

void handle_particles(registry& registry, int dt){
    auto spatial_view = registry.view<Spatial, Velocity>();

    for(auto ent : spatial_view){
        auto& spatial = spatial_view.get<Spatial>(ent);
        auto& velocity = spatial_view.get<Velocity>(ent);

        spatial.position.x += velocity.vector.x * dt / (1 SECOND);
        spatial.position.y += velocity.vector.y * dt / (1 SECOND);
    }

    auto velocity_view = registry.view<Velocity, Acceleration>();

    for(auto ent : velocity_view){
        auto& velocity = velocity_view.get<Velocity>(ent);
        auto& acceleration = velocity_view.get<Acceleration>(ent);

        acceleration.vector.x += velocity.vector.x * dt / (1 SECOND);
        acceleration.vector.y += velocity.vector.y * dt / (1 SECOND);
    }
}
