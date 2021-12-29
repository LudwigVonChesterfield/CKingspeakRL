#include "interactable.hpp"

void enact_plans(registry& registry){
    auto view = registry.view<Interactable>();

    for(auto ent : view){
        auto& interactable = view.get<Interactable>(ent);

        while(!interactable.planned.empty()){
            Action* action = interactable.planned.front();
            interactable.planned.pop();
            action->perform(registry, ent);
        }
    }
}
