#include <raylib.h>
#include <entt/entity/registry.hpp>
#include "components.hpp"

int main(){
    // Initialize Window and Configurations    
    InitWindow(1920, 1080, "Kitty Quest");
    SetTargetFPS(60);
    
    entt::registry registry;

    entt::entity GroundEntity = registry.create();
    registry.emplace<SpriteEx>(
        GroundEntity, 
        LoadTexture("assets/ground.png"),
        1.0f,
        Vector2{0, 400},
        0.0f,
        WHITE
    );

    entt::entity PlayerEntity = registry.create();
    registry.emplace<SpritePro>(
        PlayerEntity,
        LoadTexture("assets/walking-anim.png"),
        (Rectangle){
            .x = 0,
            .y = 0,
            .width = 218,
            .height = 296,
        },
        0.5f,
        (Vector2){800, 500},
        0.0f,
        WHITE,
        Vector2{0,0}
    );

    // Colors
    Color BgColor = {189, 150, 146, 255};

    // Game Loop
    while(!WindowShouldClose()){
        // Update
        if (IsKeyPressed(KEY_F11)){
            ToggleFullscreen();
        }
        
        // Drawing
        BeginDrawing();
        ClearBackground(BgColor);

        // Draw the ground entity
        auto & GroundSpriteEx = registry.get<SpriteEx>(GroundEntity);
        DrawTextureEx(GroundSpriteEx.SpriteTexture, GroundSpriteEx.Position, GroundSpriteEx.Rotation,
        GroundSpriteEx.Scale, GroundSpriteEx.Tint);

        //Draw the player entity
        auto& PlayerSpritePro = registry.get<SpritePro>(PlayerEntity);
        DrawTexturePro(PlayerSpritePro.SpriteTexture, PlayerSpritePro.SrcRect,
            (Rectangle){
                PlayerSpritePro.Position.x,
                PlayerSpritePro.Position.y,
                PlayerSpritePro.SrcRect.width*PlayerSpritePro.Scale,
                PlayerSpritePro.SrcRect.height*PlayerSpritePro.Scale,
            },
            PlayerSpritePro.Origin,
            PlayerSpritePro.Rotation,
            PlayerSpritePro.Tint
        );

        DrawFPS(10, 10);
        EndDrawing();
    }
 
    CloseWindow();
    return 0;
}
