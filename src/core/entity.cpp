#include "entity.hpp"

entt::entity Entity::GetEntityID(){
    return EntityID;
}

Scene& Entity::GetScene(){
    return MyScene;
}