#include "sprite.hpp"

Sprite::Sprite(const char* filename, Vector2 Position, float Scale){
    SpriteTexture = LoadTexture(filename);
    this->Position = Position;
    this->Scale = Scale;
    Rotation = 0.0f;
    Tint = WHITE;
}

void Sprite::Draw(){
    DrawTextureEx(SpriteTexture, Position, Rotation, Scale, Tint);
}

Sprite::~Sprite(){
    UnloadTexture(SpriteTexture);
}