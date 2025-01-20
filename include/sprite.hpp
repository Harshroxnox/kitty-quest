#pragma once
#include <raylib.h>

class Sprite {
    public:
        Sprite();
        ~Sprite();
        void Draw();
    private:
        float Scale;
        Texture2D Texture;
        Rectangle SrcRect;
        Rectangle DesRect;
        Vector2 Origin;
        float Rotation;
        Color Tint;
};