#include "scene.hpp"
#include <raylib.h>
#include "components.hpp"
#include "utils.hpp"

void Scene::LoadScene(){
    // Loads Texture
    LoadTextures<SpriteExComp>(registry);
    LoadTextures<SpriteProComp>(registry);

    // Loads Fonts
    LoadFonts<TextExComp>(registry);
    LoadFonts<TextProComp>(registry);

    // Loads Sound
    LoadSounds<SoundComp>(registry);
}