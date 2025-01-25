#include "utils.hpp"
#include "components.hpp"

void LoadSounds(entt::registry& registry){
    auto view = registry.view<SoundComp>();
    for(auto entity: view){
        auto &comp = registry.get<SoundComp>(entity);
        comp.Audio = LoadSound(comp.Filepath);
    }
}

void UnloadSounds(entt::registry& registry){
    auto view = registry.view<SoundComp>();
    for(auto entity: view){
        auto &comp = registry.get<SoundComp>(entity);
        UnloadSound(comp.Audio);
        comp.Audio = {0};
    }
}