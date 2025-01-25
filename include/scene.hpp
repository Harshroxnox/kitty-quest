#pragma once
#include "entity.hpp"
#include "entt/entity/registry.hpp"
#include <functional>
#include <string>
#include <utility>

class Scene {
    public:
        bool IsLoaded();
        // Adding texture,font,sound Entity after scene is loaded leads to undefined behaviour
        Entity AddEntity();
        bool RemoveEntity(Entity entity);
        bool HasEntity(Entity entity);
        // NOTE: The order in which you add systems is the order in which they get executed
        bool AddSystem(std::string SystemName, std::function<void(entt::registry&)> SystemFunc);
        bool RemoveSystem(std::string SystemName);
        bool HasSystem(std::string SystemName);

    private:
        // This checks if the scene is already loaded before loading 
        void LoadScene();
        void UnloadScene();
        bool IsLoadedVal = false;
        void RunSystems();
        entt::registry registry;
        std::vector<std::pair<std::string, std::function<void(entt::registry&)>>> systems;
        
    friend class Entity;
    friend class SceneManager;
};