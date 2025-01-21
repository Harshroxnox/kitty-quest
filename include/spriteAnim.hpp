// Animated 2D sprite that renders using DrawTexturePro
#pragma once
#include <raylib.h>

class SpriteAnim {
    public:
        SpriteAnim(const char* filename, Rectangle SrcRect, Vector2 Position, float Scale, Vector2 Origin,
        float Rotation, Color Tint);
        void Unload();
        void Draw();
        void SetScale(float Scale);
    private:
        Texture2D SpriteTexture;
        Rectangle SrcRect;
        Rectangle DestRect;
        Vector2 Origin;
        float Rotation;
        Color Tint;
        float Scale;
};
