#include "scene.hpp"
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