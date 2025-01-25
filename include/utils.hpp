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
void UnloadTextures(entt::registry& registry){
    auto view = registry.view<ComponentType>();
    for(auto entity: view){
        auto &comp = registry.get<ComponentType>(entity);
        UnloadTexture(comp.SpriteTexture);
        comp.SpriteTexture = {0};
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
void UnloadFonts(entt::registry& registry){
    auto view = registry.view<ComponentType>();
    for(auto entity: view){
        auto &comp = registry.get<ComponentType>(entity);
        UnloadFont(comp.TextFont);
        comp.TextFont = {0};
    }
}

void LoadSounds(entt::registry& registry);

void UnloadSounds(entt::registry& registry);
