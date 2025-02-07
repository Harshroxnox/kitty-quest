#include "scene.hpp"
#include "entity.hpp"
#include <raylib.h>
#include "components.hpp"
#include "utils.hpp"
#include "sceneManager.hpp"
#include <iostream>

// Loads textures, fonts and sounds for all entities within that scene
void Scene::LoadScene(){
    if(!IsLoadedVal){
        // Loads Texture
        LoadTextures<SpriteExComp>(registry);
        LoadTextures<SpriteProComp>(registry);

        // Loads Fonts
        LoadFonts<TextExComp>(registry);
        LoadFonts<TextProComp>(registry);

        // Loads Sound
        LoadSounds(registry);
    }
    IsLoadedVal = true;
}

// Unloads textures, fonts and sounds for all entities within that scene
void Scene::UnloadScene(){
    if(IsLoadedVal){
        // Unloads Texture
        UnloadTextures<SpriteExComp>(registry);
        UnloadTextures<SpriteProComp>(registry);

        // Unloads Fonts
        UnloadFonts<TextExComp>(registry);
        UnloadFonts<TextProComp>(registry);

        // Unloads Sound
        UnloadSounds(registry);
    }
    IsLoadedVal = false;
}

bool Scene::IsLoaded(){
    return IsLoadedVal;
}

Entity Scene::AddEntity(){
    entt::entity EntityID = registry.create();
    return Entity(EntityID, *this);
}

bool Scene::RemoveEntity(Entity entity){
    if(!registry.valid(entity.GetEntityID())){
        return false;
    }

    registry.destroy(entity.GetEntityID());
    return true;
}

bool Scene::HasEntity(Entity entity){
    return registry.valid(entity.GetEntityID());
}

bool Scene::AddSystem(std::string SystemName, std::function<void(entt::registry&)> SystemFunc){
    // Check if same name system already present
    for(auto pair: systems){
        if(pair.first == SystemName){
            return false;
        }
    }

    systems.push_back({SystemName, SystemFunc});
    return true;
}

bool Scene::RemoveSystem(std::string SystemName){
    for(auto it=systems.begin(); it!=systems.end(); it++){
        if(it->first == SystemName){
            systems.erase(it);
            return true;
        }
    }
    return false;
}

bool Scene::HasSystem(std::string SystemName){
    for(auto& pair:systems){
        if(pair.first == SystemName){
            return true;
        }
    }
    return false;
}

void Scene::RunSystems(){
    for(auto &pair:systems){
        pair.second(registry);
    }
}