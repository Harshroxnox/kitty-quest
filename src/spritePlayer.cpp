#include "spritePlayer.hpp"

SpritePlayer::SpritePlayer(const char* filename, Rectangle SrcRect, Vector2 Position, float Scale, 
Vector2 Origin, float Rotation, Color Tint):SpriteAnim(filename, SrcRect, Position, Scale, Origin,
Rotation, Tint){
    speed = 8;
}

void SpritePlayer::move(){
    if(IsKeyDown(KEY_D)){
        ChangePos((Vector2){speed,0});
    }
    if(IsKeyDown(KEY_A)){
        ChangePos((Vector2){-speed,0});
    }
}