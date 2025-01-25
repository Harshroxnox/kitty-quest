#include "game.hpp"
#include <raylib.h>
#include <entt/entity/registry.hpp>
#include "components.hpp"
#include "sceneManager.hpp"
#include <iostream>

Game& Game::Get(){
    static Game instance;
    return instance;
}

void Game::Init(){
    Get().InitInternal();
}

void Game::Run(){
    Get().RunInternal();
}

void Game::InitInternal(){
    // do initialization stuff
    // Initialize Window and Configurations
    InitWindow(1920, 1080, "Kitty Quest");
    SetTargetFPS(60);
}

void Game::RunInternal(){
    
    SceneManager::Get();

    Scene& CurrScene = SceneManager::GetCurrentScene();

    // Do stuff with current scene add entities, add components to entities, add systems

    // Colors
    Color BgColor = {189, 150, 146, 255};

    // do update stuff
    while(!WindowShouldClose()){
        // Update
        if (IsKeyPressed(KEY_F11)){
            ToggleFullscreen();
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BgColor);

        DrawFPS(10, 10);
        EndDrawing();
    }
    
    CloseWindow();
}