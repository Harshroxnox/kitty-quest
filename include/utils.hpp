# pragma once
#include <raylib.h>
#include <entt/entity/registry.hpp>

template<typename ComponentType>
void LoadTextures(entt::registry& registry){
    auto view = registry.view<ComponentType>();
    for(auto entity: view){
        auto &comp = registry.get<ComponentType>(entity);
        comp.SpriteTexture = LoadTexture(comp.Filepath);
    }
}

template<typename ComponentType>
void LoadFonts(entt::registry& registry){
    auto view = registry.view<ComponentType>();
    for(auto entity: view){
        auto &comp = registry.get<ComponentType>(entity);
        comp.TextFont = LoadFont(comp.Filepath);
    }
}

template<typename ComponentType>
void LoadSounds(entt::registry& registry){
    auto view = registry.view<ComponentType>();
    for(auto entity: view){
        auto &comp = registry.get<ComponentType>(entity);
        comp.Audio = LoadSound(comp.Filepath);
    }
}

