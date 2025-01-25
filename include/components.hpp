#include <raylib.h>

struct SpriteExComp {
    Texture2D SpriteTexture;
    char * Filepath;
    float Scale;
    Vector2 Position;
    float Rotation;
    Color Tint;
};

struct SpriteProComp {
    Texture2D SpriteTexture;
    char * Filepath;
    Rectangle SrcRect;
    float Scale;
    Vector2 Position;
    float Rotation;
    Color Tint;
    Vector2 Origin;
};

struct TextExComp {
    Font TextFont;
    char * Filepath;
    char* Text;
    Vector2 Position;
    float FontSize;
    float Spacing;
    Color Tint;
};

struct TextProComp {
    Font TextFont;
    char * Filepath;
    char* Text;
    Vector2 Position;
    Vector2 Origin;
    float Rotation;
    float FontSize;
    float Spacing;
    Color Tint;
};

struct SoundComp {
    Sound Audio;
    char * Filepath;
};