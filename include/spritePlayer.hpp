#include "spriteAnim.hpp"
#include "raylib.h"

class SpritePlayer: public SpriteAnim{
    public:
        SpritePlayer(const char* filename, Rectangle SrcRect, Vector2 Position, float Scale, Vector2 Origin,
        float Rotation, Color Tint);
        void move();
    private:
        float speed;
};