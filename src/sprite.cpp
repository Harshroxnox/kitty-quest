#include "sprite.hpp"

Sprite::Sprite(const char* filename, Vector2 Position, float Scale, float Rotation, Color Tint){
    SpriteTexture = LoadTexture(filename);
    SetTextureFilter(SpriteTexture, TEXTURE_FILTER_TRILINEAR);
    this->Position = Position;
    this->Scale = Scale;
    this->Rotation = Rotation;
    this->Tint = Tint;
}

void Sprite::Draw(){
    DrawTextureEx(SpriteTexture, Position, Rotation, Scale, Tint);
}

void Sprite::Unload(){
    if(IsTextureValid(SpriteTexture)){ 
        UnloadTexture(SpriteTexture);
    }
}