#pragma once
#include <entt/entity/registry.hpp>
#include "scene.hpp"

/* The Entity:-
It is mainly responsible for adding, removing or getting components for that entity
It is basically a light wrapper around entt entity
*/

class Entity {
    public:
        Entity(entt::entity EntityID, Scene& MyScene)
            :EntityID(EntityID), MyScene(MyScene) {}
        
        template<typename T, typename... Args>
        T& AddComponent(Args&&... args){
            return MyScene.registry.emplace<T>(EntityID, std::forward<Args>(args)...);
        }

        template<typename T>
        T& GetComponent(){
            return MyScene.registry.get<T>(EntityID);
        }

        template<typename T>
        void RemoveComponent(){
            MyScene.registry.remove<T>(EntityID);
        }

        template<typename T>
        bool HasComponent(){
            return MyScene.registry.all_of<T>(EntityID);
        }

        entt::entity GetEntityID();
        Scene& GetScene();
    private:
        entt::entity EntityID;
        Scene& MyScene;
};