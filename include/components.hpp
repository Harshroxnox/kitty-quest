#include <raylib.h>

struct SpriteEx {
    Texture2D SpriteTexture;
    float Scale;
    Vector2 Position;
    float Rotation;
    Color Tint;
};

struct SpritePro {
    Texture2D SpriteTexture;
    Rectangle SrcRect;
    float Scale;
    Vector2 Position;
    float Rotation;
    Color Tint;
    Vector2 Origin;
};