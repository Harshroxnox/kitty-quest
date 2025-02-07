#include "entity.hpp"
#include "scene.hpp"

entt::entity Entity::GetEntityID(){
    return EntityID;
}

Scene& Entity::GetScene(){
    return MyScene;
}