#include <raylib.h>

int main(){    
    InitWindow(1920, 1080, "Kitty Quest");

    // For fullscreen uncomment
    // ToggleFullscreen();
    Color BgColor = {189, 150, 146, 255};

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(BgColor);

        EndDrawing();
    }



    CloseWindow();
    return 0;
}
