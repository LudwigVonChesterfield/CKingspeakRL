#include "temporary.hpp"

void handle_temporary(registry& registry, int dt){
    auto view = registry.view<Temporary>();

    for(auto ent : view){
        auto& temporary = view.get<Temporary>(ent);

        temporary.time_to_live -= dt;
        if(temporary.time_to_live < 0){
            registry.destroy(ent);
        }
    }
}
