#include <raylib.h>
#include "sprite.hpp"
#include "spriteAnim.hpp"

int main(){
    // Initialize Window and Configurations    
    InitWindow(1920, 1080, "Kitty Quest");
    SetTargetFPS(250);

    // Colors
    Color BgColor = {189, 150, 146, 255};

    Sprite ground("assets/ground.png", (Vector2){0,0}, 1.0f, 0.0f, WHITE);
    SpriteAnim player(
        "assets/walking-anim.png", 
        (Rectangle){
            .x = 0,
            .y = 0,
            .width = 218,
            .height = 296,
        },
        (Vector2){600, 500},
        0.5,
        (Vector2){0,0},
        0.0f,
        WHITE
    );

    // Game Loop
    while(!WindowShouldClose()){
        // Update
        if (IsKeyPressed(KEY_F11)){
            ToggleFullscreen();
        }
        
        // Drawing
        BeginDrawing();
        ClearBackground(BgColor);
        ground.Draw();
        player.Draw();

        DrawFPS(10, 10);
        EndDrawing();
    }

    ground.Unload();
    player.Unload();
 
    CloseWindow();
    return 0;
}
