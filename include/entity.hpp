#pragma once
#include <entt/entity/registry.hpp>
#include "scene.hpp"

class Entity {
    public:
        Entity(entt::entity EntityID, Scene& MyScene)
            :EntityID(EntityID), MyScene(MyScene) {}
        entt::entity GetEntityID();
        Scene& GetScene();
    private:
        entt::entity EntityID;
        Scene& MyScene;
};