#include <raylib.h>

typedef struct Sprite {
    float Scale;
    Texture2D Texture;
    Rectangle SrcRect;
    Rectangle DestRect;
    Vector2 Origin = {0,0};
    float Rotation = 0.0f;
    Color Tint = WHITE;
}Sprite;

int main(){
    // Initialize Window and Configurations    
    InitWindow(1920, 1080, "Kitty Quest");
    SetTargetFPS(250);

    // Colors
    Color BgColor = {189, 150, 146, 255};

    // Load Textures
    Texture2D GroundTexture = LoadTexture("assets/ground.png"); 
    Texture2D PlayerRight = LoadTexture("assets/walking-anim.png");
    SetTextureFilter(PlayerRight, TEXTURE_FILTER_TRILINEAR);

    // Player
    Sprite player = (Sprite){
        .Scale = 0.5,
        .Texture = PlayerRight,
        .SrcRect = (Rectangle){
            .x = 0,
            .y = 0,
            .width = 218,
            .height = 296,
        },
        .DestRect = (Rectangle){
            .x = 300,
            .y = 500,
            .width = player.SrcRect.width*player.Scale,
            .height = player.SrcRect.height*player.Scale,
        }
    };

    // Ground
    Sprite ground = (Sprite){
        .Scale = 1,
        .Texture = GroundTexture,
        .SrcRect = (Rectangle){
            .x = 0,
            .y = 0,
            .width = (float)GroundTexture.width,
            .height = (float)GroundTexture.height,
        },
        .DestRect = (Rectangle){
            .x = 0,
            .y = 1080-ground.SrcRect.height,
            .width = ground.SrcRect.width*ground.Scale,
            .height = ground.SrcRect.height*ground.Scale,
        }
    };

    // Game Loop
    while(!WindowShouldClose()){
        // Update
        if (IsKeyPressed(KEY_F11)){
            ToggleFullscreen();
        }
        
        // Drawing
        BeginDrawing();
        ClearBackground(BgColor);

        DrawTexturePro(player.Texture, player.SrcRect, player.DestRect, 
        player.Origin, player.Rotation, player.Tint);
        DrawTexturePro(ground.Texture, ground.SrcRect, ground.DestRect, 
        ground.Origin, ground.Rotation, ground.Tint);

        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadTexture(PlayerRight);
    UnloadTexture(GroundTexture);

    CloseWindow();
    return 0;
}
