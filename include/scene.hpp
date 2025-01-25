#pragma once
#include "entity.hpp"
#include "entt/entity/registry.hpp"
#include <functional>
#include <string>
#include <utility>

class Scene {
    public:
        bool IsLoaded();
        Entity AddEntity();
        bool RemoveEntity(Entity entity);
        bool HasEntity(Entity entity);
        bool AddSystem(std::string SystemName, std::function<void(entt::registry&)> system);
        bool RemoveSystem(std::string SystemName);
        bool HasSystem();

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