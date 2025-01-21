// A Basic non-animated 2D sprite which can be scaled, rotated and tinted. Its drawn using DrawTextureEx
#pragma once
#include <raylib.h>

class Sprite {
    public:
        Sprite(const char* filename, Vector2 Position, float Scale, float Rotation, Color Tint);
        void Unload();
        void Draw();
    private:
        Texture2D SpriteTexture;
        float Scale;
        Vector2 Position;
        float Rotation;
        Color Tint;
};